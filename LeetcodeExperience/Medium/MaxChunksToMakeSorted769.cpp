#include<iostream>
#include<vector>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {

    int curMax = -1;
    int res = 0;

    for(int i = 0; i < arr.size(); i++){
        curMax = max(arr[i], curMax);

        if(curMax == i){
            res += 1;
        }
    }

    return res;       
}

// 1 0  4 3 2