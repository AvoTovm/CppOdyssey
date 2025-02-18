#include <string>
#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s)  {

    int m = s.size();
    string s2(s.rbegin(), s.rend());

    vector<vector<int>> DP(m + 1, vector<int>(m + 1, 0));

    for(int i = m - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(s[i] == s2[j]){
                DP[i][j] = DP[i + 1][j + 1] + 1;
            }else{
                DP[i][j] = max(DP[i + 1][j], DP[i][j + 1] );
            }
        }
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }

    return DP[0][0];


}

int main(){

    string a = "bbbab";

    longestPalindromeSubseq(a );
}