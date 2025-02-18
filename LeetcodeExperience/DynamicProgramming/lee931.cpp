#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int minFallingPathSum(vector<vector<int>>& matrix){
        
        int n = matrix.size(); //row

        if(n == 0){
            return 0;
        }
        int m = matrix[0].size(); //col

        if(m == 0){
            return 0;
        }

        for(int i = n - 2; i >= 0 ; i--){
            matrix[i][0] += min(matrix[i + 1][0], matrix[i + 1][1]);
            matrix[i][m - 1] += min(matrix[i + 1][m - 1], matrix[i + 1][m - 2]);
            for(int j = 1; j < m - 1; j++){  
                matrix[i][j] += min(matrix[i + 1][j - 1], min(matrix[i + 1][j], matrix[i + 1][j + 1]));
            }
        }
        
        
        return *min_element(matrix[0].begin(), matrix[0].end());
    }


int main() {
    
    std::vector<std::vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    minFallingPathSum(grid);

}
