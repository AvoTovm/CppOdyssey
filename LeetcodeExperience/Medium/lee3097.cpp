#include<iostream>
#include<vector>


using namespace std;

void bits_update(vector<int>& bits, int n, int diff){
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                bits[i] += diff;
            }
        }
    }

int bits_to_int(vector<int>& bits){
    int res = 0;
    for(int i = 0; i < 32; i++){
        if(bits[i]){
            res += (1 << i);
        }
    }
    return res;
}

int minimumSubarrayLength(vector<int>& nums, int k) {   
    
    int res = 10000000;
    vector<int> bits(32,0);

    int l = 0;
    int cur_or;
    for(int r = 0; r < nums.size(); r++){
        bits_update(bits, nums[r], 1);
        cur_or = bits_to_int(bits);
        while(l <= r && cur_or >= k){
            res = min(res, r - l + 1);
            bits_update(bits, nums[l], -1);
            cur_or = bits_to_int(bits);
            l++;
        }

    }

    if( res == 10000000){
        return -1;
    }else{
        return res;}
    

}

int main(){
    vector<int> a = {2,1,8};
    int k = 10;

    cout<<minimumSubarrayLength(a,k);
}