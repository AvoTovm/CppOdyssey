#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumDeleteSum(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> DP(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--) {
        DP[i][n] = DP[i + 1][n] + word1[i];
    }
    for (int j = n - 1; j >= 0; j--) {
        DP[m][j] = DP[m][j + 1] + word2[j];
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (word1[i] == word2[j]) {
                DP[i][j] = DP[i + 1][j + 1];
            } else {
                DP[i][j] = min(DP[i + 1][j] + word1[i], DP[i][j + 1] + word2[j]);
            }
        }
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }

    return DP[0][0];
}

int main() {
    string a = "sea";
    string b = "eat";
    
    cout << "Minimum ASCII delete sum: " << minimumDeleteSum(a, b) << endl;

    return 0;
}
