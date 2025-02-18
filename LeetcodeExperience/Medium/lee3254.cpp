#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isSorted(vector<int>& vec){
    return std::adjacent_find(vec.begin(), vec.end(), [](int a, int b) {
        return b - a != 1;
    }) == vec.end();
};

vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> res;
    vector<int> temp;

    for(int i = 0; i < nums.size() - k + 1; i++){
        temp.clear();

        for(int j = 0; j < k; j++){
            temp.push_back(nums[i + j]);
        }
        if(isSorted(temp)){
            res.push_back(temp[k - 1]);
        }else{
            res.push_back(-1);
        }
        
    }

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }

    return res;
}

int main(){

    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;

    resultsArray(nums,k);
}