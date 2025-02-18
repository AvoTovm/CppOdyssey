#include <string>
#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {

    int m = word1.size();
    int n = word2.size();

    if(word1.empty() && word2.empty()){
        return 0;
    }

    if(word1.empty()){
        return n;
    }

    if(word2.empty()){
        return m;
    }

    vector<vector<int>> DP(m + 1, vector<int>(n + 1, 0));

    for(int i = 0; i < m; i++){
        DP[i][n] = m - i;
    }

    for(int i = 0; i < n; i++){
        DP[m][i] = n - i;
    }

    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(word1[i] == word2[j]){
                DP[i][j] = DP[i + 1][j + 1];
            }else{
                DP[i][j] = min(min(DP[i][j + 1], DP[i + 1][j]), DP[i + 1][j + 1]) + 1;
            }
        }
    }

    return DP[0][0];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    string a = "abbd";
    string b = "ack";

    minDistance(a,b);
}
