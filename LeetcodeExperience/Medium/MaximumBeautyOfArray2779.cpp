#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();
    int maxBeauty = 0;

    sort(nums.begin(), nums.end());

    int left = 0;
    for(int right = 0; right < n; right++){
        while(nums[right] > nums[left] + 2 * k){
            left++;
        }

        maxBeauty = max(maxBeauty, right - left + 1);
    }

    return maxBeauty;
}

int main() {
    int k = 12;
    vector<int> nums = {49, 26};

    cout<<maximumBeauty(nums, k);
}
