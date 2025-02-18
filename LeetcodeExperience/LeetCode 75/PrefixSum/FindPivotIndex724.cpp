#include<iostream>
#include<vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) sum += nums[i];

    int leftSum = 0;

    for(int i = 0; i < nums.size(); i++){
        int rightSum = sum - nums[i] - leftSum;
        if(leftSum == rightSum) return i;
        leftSum += nums[i];
    }
    return -1;

}

int main(){
    vector<int> nums = {1,7,3,6,5,6};

    cout<<pivotIndex(nums);
}