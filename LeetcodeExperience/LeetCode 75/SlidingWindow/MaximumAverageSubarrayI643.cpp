#include<iostream>
#include<vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double maxNum = 0;

    for(int i = 0; i < k; i++){
        maxNum += nums[i];
    }

    double tempMax = maxNum;
    
    for(int i = 1; i < nums.size() - k + 1; i++){
        tempMax = (tempMax - nums[i - 1]) + nums[i + k - 1];
        maxNum = max(maxNum, tempMax);
    }

    return maxNum / k; 
}

int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout<<findMaxAverage(nums, k);
}