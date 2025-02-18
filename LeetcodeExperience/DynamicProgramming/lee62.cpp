#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {

        if(n && m == 0){
            return 0;
        }

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            matrix[m - 1][i] = 1;
        }
        for(int i = 0; i < m; i++){
            matrix[i][n  - 1] = 1;
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                matrix[i][j] = (matrix[i + 1][j] + matrix[i][j + 1]);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j]<<" ";
            }cout <<"\n";
        }

        return matrix[0][0];


    }

int main() {
    
    int n = 7;
    int m = 3;

    uniquePaths(m,n);

}
