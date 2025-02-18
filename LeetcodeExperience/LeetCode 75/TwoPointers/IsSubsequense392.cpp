#include<iostream>

using namespace std;

bool isSubsequence(string s, string t) {
    int r = 0;
    int l = 0;

    if(s.empty() && t.empty()){
        return true;
    }

    while(max(s.size(), t.size()) > r){
        if(s[l] == t[r]){
            l++;
        }
        r++;

        if(l == s.size()){
            return true;
        }
    }
    return false;
}

int main(){
    string s = "axc";
    string t = "ahbgdc";

    cout<<isSubsequence(s,t);
}