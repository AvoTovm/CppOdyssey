#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = *max_element(quantities.begin(), quantities.end());
    int res = 0;

    while(l <= r){
        int x = (l + (r - 1)) / 2;
        int stores = 0;
        for(int j = 0; j < quantities.size(); j++){
            stores += (quantities[j] + x - 1) / x;
        }
        if(stores <= n){
            res = x;
            r = x - 1;
        }else{
            l = x + 1;
        }


    }
    return res;


}

int main(){
    int n = 6;
    vector<int> quan = {11,6};

    cout<<minimizedMaximum(n,quan);
}