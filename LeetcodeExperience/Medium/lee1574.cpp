#include<iostream>
#include<vector>

using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    //remove Prefix
    int k = arr.size();
    int r = k - 1;

    while(r > 0 && arr[r - 1] <= arr[r]) r--;
    int res = r;

    //remove Postfix
    int l = 0;
    while(l + 1 < k && arr[l] <= arr[l + 1]) l++;
    res = min(res, k - 1 - l);

    //remove middle
    l = 0; 
    r = k - 1;

    while(l < r){
        while(r < k && l + 1 < r && arr[r - 1] <= arr[r] && arr[l] <= arr[r]) r--;

        while(r < k && arr[l] > arr[r]) r++;

        res = min(res, r - l - 1);
        if(arr[l] > arr[l + 1]){
            break;
        }
        l++;
    }
    return res;
}