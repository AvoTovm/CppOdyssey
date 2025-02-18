#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> nums1Set(nums1.begin(), nums1.end());
    unordered_set<int> nums2Set(nums2.begin(), nums2.end());
    vector<int> res1, res2;

    for(int n : nums1){
        if(nums2Set.count(n) == 0){
            res1.push_back(n);
        }
    }

    for(int n : nums2){
        if(nums1Set.count(n) == 0){
            res2.push_back(n);
        }
    }

    unordered_set<int> uniqueRes1(res1.begin(), res1.end());
    unordered_set<int> uniqueRes2(res2.begin(), res2.end());

    return {vector<int>(uniqueRes1.begin(), uniqueRes1.end()),
            vector<int>(uniqueRes2.begin(), uniqueRes2.end())};

}

int main(){
    vector<int> nums1 = {1,2,3,3};
    vector<int> nums2 = {1,1,2,2};

    vector<vector<int>> result = findDifference(nums1, nums2);

    for (const auto& vec : result) {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;
}