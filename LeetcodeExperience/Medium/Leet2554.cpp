#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end());
    int currentSum = 0, count = 0;

    for(int i = 1; i <= n; ++i){
        if(bannedSet.find(i) != bannedSet.end()) continue;
        if(currentSum + i > maxSum) break; 

        currentSum += i;
        ++count;
    }

    return count;
}

int main(){
    vector<int> banned = {11};
    int n = 8, maxSum = 29;
    cout<<maxCount(banned, n, maxSum);
}