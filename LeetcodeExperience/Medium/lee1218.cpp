#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> dp;
    int maxLength = 1;

    for (int num : arr) {
        dp[num] = dp[num - difference] + 1;
        maxLength = max(maxLength, dp[num]);
    }

    return maxLength;
}

int main(){
    vector<int> arr = {1,5,7,8,5,3,4,2,1};

    int dif = -2;

    cout<<longestSubsequence(arr, dif);
}