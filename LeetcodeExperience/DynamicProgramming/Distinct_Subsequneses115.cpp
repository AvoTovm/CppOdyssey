#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDistinct(string s, string t) {
    const int MOD = 1e9 + 7;

    int m = s.size();
    int n = t.size();

    vector<vector<long long>> DP(m + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        DP[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j] % MOD;
            } else {
                DP[i][j] = DP[i - 1][j] % MOD;
            }
        }
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }

    return DP[m][n];
}

int main() {
    string s = "rabbbit";
    string t = "rabbit";

    cout << "Number of distinct subsequences " << numDistinct(s, t) << endl;

    return 0;
}
