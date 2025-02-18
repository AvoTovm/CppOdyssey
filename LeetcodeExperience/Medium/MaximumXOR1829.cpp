#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int numxor = 0;

    for(int n : nums){
        numxor = numxor ^ n;
    }

    int k = nums.size();
    int temp = pow(2, maximumBit) - 1;

    vector<int> result(k);
    int l = 0;

    for(int i = k - 1; i >= 0; i--){
        result[l] = numxor ^ temp;
        numxor = numxor ^ nums[i];
        l++;
    }

    return result;
}

int main(){
    vector<int> nums = {0,1,1,3};
    int maxbit = 2;

    getMaximumXor(nums, maxbit);

}