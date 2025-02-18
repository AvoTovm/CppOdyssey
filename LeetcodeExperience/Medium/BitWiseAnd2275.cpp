#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int largestCombination(vector<int>& candidates) {
    vector<int> count(32, 0);

    int i = 0;
    for(int num : candidates){
        i = 0;
        while(num > 0){
            count[i] += 1 & num;
            i++;
            num = num >> 1;
        }
    }

    return *max_element(count.begin(), count.end()); 

}


int main() {
    vector<int>  candidates = {16,17,71,62,12,24,14};

    cout<<largestCombination(candidates);

}