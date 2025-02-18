#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool canDivide(vector<int>& nums, int maxOperations, int maxBalls){
    int ops = 0;
    for(int n : nums){
        ops += ceil((double)n / maxBalls) - 1;
        if(ops > maxOperations){
            return false;
        }
    }
    return true;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end());
    int res = r;

    while(l < r){
        int m = l + (r - l) / 2;
        if(canDivide(nums, maxOperations, m)){
            r = m;
            res = r;
        }else{
            l = m + 1;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {7,17};
    int maxOp = 2;

    cout<<minimumSize(nums, maxOp);
}