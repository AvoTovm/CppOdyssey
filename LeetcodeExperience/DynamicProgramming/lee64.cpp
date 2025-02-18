#include <iostream>
#include <vector>
using namespace std;

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(); //row
        int m = grid[0].size(); // column

        //for last row
        for(int i = n - 2; i >= 0; i--){
            grid[m - 1][i] = grid[m - 1][i] + grid[m - 1][i + 1];
        }

        //for last column
        for(int i = m - 2; i >= 0; i--){
            grid[i][n - 1] = grid[i][n - 1] + grid[i + 1][n - 1];
        }

        

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j-- ){
                grid[i][j] = min((grid[i][j] + grid[i + 1][j]),(grid[i][j] + grid[i][j + 1]));
            }
        }
        for(int i = 0; i < m; i++){
                    for(int j = 0 ; j < n; j++){
                        cout<<grid[i][j]<<" ";
                    }
                    cout<<endl;
                }
        return grid[0][0];

    }


int main() {
    
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    minPathSum(grid);

}
