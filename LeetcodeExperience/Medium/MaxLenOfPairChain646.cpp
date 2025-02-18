#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {

    sort(pairs.begin(), pairs.end());

    int k = pairs.size() ;
    vector<int> DP(k, 1);

    for(int i = k - 2; i >= 0; i--){
        for(int j = i + 1; j < k; j++){
          if(pairs[i][1] < pairs[j][0]){
            DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        
    }

    return *max_element(DP.begin(), DP.end());
}

int main() {
    vector<vector<int>> pairs = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    
    cout<<findLongestChain(pairs);
}
