#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    unordered_set<int> chars1, chars2;
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);


    for(char c : word1){
        freq1[c - 'a']++;
        chars1.insert(c);
    }
    for(char c : word2){
        freq2[c - 'a']++;
        chars2.insert(c);
    }

    if(chars1 != chars2) return false;

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
}

int main(){
    string a = "aabc";
    string b = "bcca";

    cout<<closeStrings(a,b);
}