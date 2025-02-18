#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int max_size = 0;

    for (int num : nums) {
        int complement = k - num;

        if (map[complement] > 0) {
            max_size++;
            map[complement]--;
        } else {    
            map[num]++;
        }
    }

    return max_size;
}

int main(){
    vector<int> nums = {1,2,3,4};
    int k = 5;

    cout<<maxOperations(nums, k);
}