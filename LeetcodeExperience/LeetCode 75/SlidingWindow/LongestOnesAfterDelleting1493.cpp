#include<iostream>
#include<vector>

using namespace std;

int longestSubarray(vector<int> &nums){
    int maxOnes = 0;
    int l = 0;
    int r = 0;
    int carry = 1;

    while (r < nums.size()){
        if (nums[r] == 0) carry--;

        while (carry < 0){
            if (nums[l] == 0) carry++;
            l++;
        }
        maxOnes = max(maxOnes, r - l + 1);
        r++;
    }
    return maxOnes - 1;
}

int main(){
    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    cout<<longestSubarray(nums);
}