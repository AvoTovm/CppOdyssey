#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int takeCharacters(string s, int k) {
    vector<int> count = {0,0,0};
    for(char c : s){
        count[c - 'a']++;
    }

    if(*min_element(count.begin(), count.end()) < k){
        return -1;
    }


    int res = numeric_limits<int>::max();
    int l = 0;
    for(int r = 0; r < s.size(); r++){
        count[s[r] - 'a']--;

        while(*min_element(count.begin(), count.end()) < k){
            count[s[l] - 'a']++;
            l++;
        }

        int o = s.size() - (r - l + 1);
        res = min(res, o);
    }

    return res;

}

int main(){
    string s = "aabaaaacaabc";
    int k = 2;

    cout<<takeCharacters(s,k);
}