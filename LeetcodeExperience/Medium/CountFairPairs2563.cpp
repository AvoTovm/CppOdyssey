#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {

            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

            if (low <= high) {
                count += (high - low + 1);
            }
        }
        return count;

}

int main(){
    std::vector<int> nums = {0, 1, 7, 4,4,5};
    int lower = 3;
    int upper = 6;

    cout<<countFairPairs(nums, lower, upper);
}