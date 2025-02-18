#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    sort(gifts.begin(), gifts.end());

    while(k > 0){
        int i = gifts.size() - 1;
        gifts[i] = sqrt(gifts[i]);
        sort(gifts.begin(), gifts.end());

        k--;
    }

    long long total = accumulate(gifts.begin(), gifts.end(), 0LL);
    return total;
}

int main(){
    vector<int> gifts = {54,6,34,66,63,52,39,62,46,75,28,65,18,37,18,13,33,69,19,40,13,10,43,61,72};
    int k = 7;

    cout<<pickGifts(gifts, k);
}