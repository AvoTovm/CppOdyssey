#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int k = nums.size();
    int r = 0;
    int l = 0;

    while(l < k && r < k){
        while(nums[r] == 0){
            r++;
        }
        while(nums[l] != 0)
            l++;

        if (l < r && l < k && r < k && nums[l] == 0 && nums[r] != 0) {
            swap(nums[l], nums[r]);
        }

        if(r <= l){
            r = l + 1;
        }
    }
    
    for(int i = 0 ; i < k ; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);
}