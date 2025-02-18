#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int k = nums.size();

    vector<int> LIS(k, 1);

    for(int i = k - 2; i >= 0; i--){
        for(int j = i + 1; j < k; j++){
          if(nums[i] < nums[j]){
            LIS[i] = max(LIS[i], LIS[j] + 1);
            }  
        }
        
    }

    return *max_element(LIS.begin(), LIS.end()); 
}

int main(){
    vector<int> a = {10, 9 , 2, 5, 3, 7, 101, 18};

    cout<<lengthOfLIS(a);
}

