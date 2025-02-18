#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i < int(sqrt(n)) + 1; i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool primeSubOperation(vector<int>& nums) {
    int prev = 0;
    for(int i = 0 ; i < nums.size(); i++){
        int upper_bound = nums[i] - prev;

        int largest_p = 0;
        for(int j = upper_bound - 1; j >= 2; j--){
            if(isPrime(j)){
                largest_p = j;
                break;
            }
        }

        if(nums[i] - largest_p <= prev){
            return false;
        }
        prev = nums[i] - largest_p;
    }
    return true;
}

int main(){
    vector<int> a = {4,9,6,10};

    cout<<primeSubOperation(a);
}