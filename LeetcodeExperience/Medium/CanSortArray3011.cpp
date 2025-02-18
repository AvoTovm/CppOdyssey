#include<iostream>
#include<vector>

using namespace std;

bool canSortArray(vector<int>& nums) {

    int curMin, curMax = nums[0];
    int prevMax = -1;

    for(int i = 0; i < nums.size(); i++){
        if(__builtin_popcount(nums[i]) == __builtin_popcount(curMin)){
            curMin = min(curMin, nums[i]);
            curMax = max(curMax, nums[i]);

        }else{
            if(curMin < prevMax){
                return false;
            }
            prevMax = curMax;
            curMax = nums[i];
            curMin = nums[i];
        }
    }
    if(curMin < prevMax){
        return false;
    }
    return true;
}

int main(){
    vector<int> nums = {8,4,2,30,15};

    if(canSortArray(nums)){
        cout<<"can";
    }else{
        cout<<"cant";
    }
}