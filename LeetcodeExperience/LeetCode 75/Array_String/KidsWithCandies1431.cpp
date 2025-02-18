#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int x = *max_element(candies.begin(), candies.end());
    int k = candies.size();

    vector<bool> res(k , false);

    for(int i = 0; i < k; i++){
        if(candies[i] + extraCandies >= x){
            res[i] = true;
        }
    }

    return res;
}