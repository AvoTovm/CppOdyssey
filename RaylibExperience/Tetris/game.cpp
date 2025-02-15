#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    curBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock(){

    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    curBlock.Draw(11, 11);
    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break; 
    }
    
}

void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }
    switch(keyPressed){

        case KEY_A:
            MoveBlockLeft();
            break;

        case KEY_D:
            MoveBlockRight();
            break;

        case KEY_S:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        
        case KEY_R:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft(){
    if(!gameOver){
        curBlock.Move(0, -1);
        if(IsBlockOutside() || BlokFits() == false){
            curBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight(){
    if(!gameOver){
        curBlock.Move(0, 1);
        if(IsBlockOutside() || BlokFits() == false){
            curBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown(){
    if(!gameOver){
        curBlock.Move(1, 0);
        if(IsBlockOutside() || BlokFits() == false){
            curBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

bool Game::IsBlockOutside()
{
    vector<Position> tiles = curBlock.GetCellPosition();
    for(Position item: tiles){
        if(grid.IsCellOutside(item.row, item.col)){
            return true;
        }
    }

    return false;
}

bool Game::BlokFits(){
    vector<Position> tiles = curBlock.GetCellPosition();
    for(Position item: tiles){
        if(grid.IsCellEmpty(item.row, item.col) == false) return false;
    }

    return true;
}

void Game::RotateBlock(){
    if(!gameOver){
        curBlock.Rotate();
        if(IsBlockOutside() || BlokFits() == false){
            curBlock.UndoRotate();
        }
    }
}

void Game::LockBlock(){
    vector<Position> tiles = curBlock.GetCellPosition();
    for(Position item: tiles){
        grid.grid[item.row][item.col] = curBlock.id;
    }
    curBlock = nextBlock;
    if(BlokFits() == false) gameOver = true;
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    curBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int LinesCleared, int moveDownPoints){
    switch (LinesCleared){
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}
