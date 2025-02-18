#include<iostream>
#include<vector>

using namespace std;

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    for(int i = 0; i < k; i++){
        int minNum = nums[0];

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] < minNum) minNum = nums[j];
        }

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == minNum){
                nums[j] = nums[j] * multiplier;
                break;
            }
        }
    }

    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }

    return nums;
}

int main(){
    vector<int> nums = {1};
    int k = 10;
    int mul = 5;

    getFinalState(nums, k, mul);
}