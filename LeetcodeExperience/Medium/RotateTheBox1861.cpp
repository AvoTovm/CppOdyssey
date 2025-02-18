#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(const vector<vector<char>>& matrix){
    for(const auto& row : matrix){
        for(char val : row){
            cout<<val<< " ";
        }
        cout<<endl;
    }
}

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int rows = box.size();
    int cols = box[0].size();
    
    vector<vector<char>> rotated(cols, vector<char>(rows));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][rows - i - 1] = box[i][j];
        }
    }

    //gravity

    int m = rotated.size();
    int n = rotated[0].size();

    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(rotated[i][j] == '.'){
                for(int k = i; k >= 0; k--){
                    if(rotated[k][j] == '*'){
                        break;
                    }else if(rotated[k][j] == '#'){
                        swap(rotated[k][j], rotated[i][j]);
                        break;
                    }

                }
            }
        }
    }


    return rotated;
}

int main() {
    vector<vector<char>> matrix = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };

    printMatrix(matrix);

    vector<vector<char>> rotated = rotateTheBox(matrix);

    cout<<endl;
    printMatrix(rotated);

}
