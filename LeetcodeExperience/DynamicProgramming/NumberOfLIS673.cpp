#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int k = nums.size();
    if (k <= 1) return k;

    vector<int> LIS(k , 1);
    vector<int> count(k , 1);


    for(int i = k - 2; i >= 0; i--){
        for(int j = i + 1; j < k; j++){
            if(nums[i] < nums[j]){
                if(LIS[i] < LIS[j] + 1){
                    LIS[i] = LIS[j] + 1;
                    count[i] = count[j];
                }else if(LIS[i] == LIS[j] + 1){
                    count[i] += count[j];
                }

            }
        }
    }

    int maxNum = *max_element(LIS.begin(), LIS.end());
    int result = 0;

    for (int i = 0; i < k; i++) {
        if (LIS[i] == maxNum) {
            result += count[i];
        }
    }

    return result;
}

int main(){
    vector<int> a = {1,2,4,3,5,4,7,2};

    cout<<findNumberOfLIS(a);
}