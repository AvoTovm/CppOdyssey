#include <iostream>
#include <unordered_map>

using namespace std;

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> countS ;
        unordered_map<char, int> countT ;

        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        for (const auto &pair : countS) {
            char c = pair.first;
            if (countS[c] != countT[c]) {
                return false;
            }
        }

        return true;
    }

    int main() {
    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s,t)){
        cout<<"true"<<"\0";
    }else{
        cout<<"false"<<"\0";
    }
}