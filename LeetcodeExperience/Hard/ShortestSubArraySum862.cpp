#include<iostream>
#include<vector>
#include<deque>
#include<limits>

using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
   int res = numeric_limits<int>::max();
        long long cur_sum = 0;
        deque<pair<long long, int>> q;

        for(int r = 0; r < nums.size(); ++r){
            cur_sum += nums[r];
            
            if(cur_sum >= k){
                res = min(res, r + 1);
            }
            
            while(!q.empty() && cur_sum - q.front().first >= k){
                res = min(res, r - q.front().second);
                q.pop_front();
            }

            while(!q.empty() && q.back().first >= cur_sum){
                q.pop_back();
            }
            q.emplace_back(cur_sum, r);
        }
        
        return res == numeric_limits<int>::max() ? -1 : res; 
}

int main(){
    vector<int> nums = {2,-1,2};
    int k = 3;

    cout<<shortestSubarray(nums,k);
}
