#include<iostream>
#include<vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int maxOnes = 0;
    int l = 0;
    int r = 0;
    int carry = k;

    while(r < nums.size()){
        if(nums[r] == 0){
            carry--;
        }

        while(carry < 0){
            if(nums[l] == 0){
                carry++;
            }
            l++;
        }

        maxOnes = max(maxOnes, r - l + 1);
        r++;

    }

    return maxOnes;
}

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout<<longestOnes(nums, k);
}