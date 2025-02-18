#include<iostream>
#include<vector>

using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<bool> res;

    vector<int> prefixAlt(n, 0);
    for (int i = 1; i < n; i++) {
        prefixAlt[i] = prefixAlt[i - 1] + (nums[i - 1] % 2 != nums[i] % 2);
    }

    for (auto& query : queries) {
        int first = query[0];
        int second = query[1];

        int alternatingPairs = prefixAlt[second] - prefixAlt[first];

        res.push_back(alternatingPairs == (second - first));
    }

    return res;
}