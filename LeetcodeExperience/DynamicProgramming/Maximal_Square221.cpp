#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();    // rows
    int m = matrix[0].size(); // columns
    int maxSquare = 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }
    }

    return maxSquare * maxSquare;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1'}
    };

    cout << maximalSquare(grid) << endl;
    return 0;
}
