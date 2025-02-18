#include<iostream>
#include<vector>
#include <utility>

using namespace std;

void markGuarded(int r,int c, int m, int n, vector<vector<int>>& grid){
    for(int row = r + 1; row < m; row++){
        if(grid[row][c] == 1 || grid[row][c] == 2 ) break;
        grid[row][c] = 3;
    }
    for(int row = r - 1; row >= 0; row--){
        if(grid[row][c] == 1 || grid[row][c] == 2 ) break;
        grid[row][c] = 3;
    }
    for(int col = c + 1; col < n; col++){
        if(grid[r][col] == 1 || grid[r][col] == 2 ) break;
        grid[r][col] = 3;
    }
    for(int col = c - 1; col >= 0; col--){
        if(grid[r][col] == 1 || grid[r][col] == 2 ) break;
        grid[r][col] = 3;
    }
}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    //guard 1; wall 2; guarded 3;

    for(const auto& guard : guards){
    int x = guard[0];
    int y = guard[1];
    grid[x][y] = 1;
    }
    for(const auto& wall : walls){
    int x = wall[0];
    int y = wall[1];
    grid[x][y] = 2;
    }

    for(const auto& guard : guards){
    int x = guard[0];
    int y = guard[1];
    markGuarded(x, y, m, n , grid);
    }

    int res = 0;
    for(auto row : grid){
        for(auto n : row){
            if(n == 0){
                res++;
            }
        }
    }

    return res;
}

int main(){
    vector<vector<int>> guards = {{0,0}, {1,1}, {2,3}};
    vector<vector<int>> walls = {{0,1}, {2,2}, {1,4}};

    int m = 4;
    int n = 6;

    cout<<countUnguarded(m,n,guards, walls);
}