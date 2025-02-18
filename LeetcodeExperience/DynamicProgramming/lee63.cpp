#include <iostream>
#include <vector>


using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {


        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[0][i] == 1) return 0; // path is blocked
        }
        return 1; // no obstacles in the single row
        }

        if (m == 1) {
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1) return 0; // path is blocked
        }
        return 1; // no obstacles in the single column
        }


        //swipe 0 and 1's
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 0){
                    obstacleGrid[i][j] = 1;
                }else{
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        

        for (int i = n - 1; i >= 0; i--) {
        if (obstacleGrid[i][m - 1] == 0) {
            for (int k = i; k >= 0; k--) {
                obstacleGrid[k][m - 1] = 0; // Set rest of column to 0
            }
            break;
        }
    }

        for (int j = m - 1; j >= 0; j--) {
        if (obstacleGrid[n - 1][j] == 0) {
            for (int k = j; k >= 0; k--) {
                obstacleGrid[n - 1][k] = 0; // Set rest of row to 0
            }
            break;
        }
    }

        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 2; j >= 0; j--){
                if(obstacleGrid[i][j] != 0){
                    obstacleGrid[i][j] = (obstacleGrid[i + 1][j] + obstacleGrid[i][j + 1]); 
                }else{
                    obstacleGrid[i][j] = 0;
                }
                
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << obstacleGrid[i][j]<<" ";
            }cout <<"\n";
        }

        return obstacleGrid[0][0];

    }




int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };

    
    
    uniquePathsWithObstacles(grid);

}