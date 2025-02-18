#include<iostream>

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true ;
    return false;
}

string reverseVowels(string s) {
    int k = s.size();

    int l = 0;
    int r = k - 1;

    while(l < r){
        while(l < r && !isVowel(s[l])){
            l++;
        }
        while(l < r && !isVowel(s[r])){
            r--;
        }

        if(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }

    }

    return s;  
}

int main(){
    string s = "IceCreAm";

    cout<<reverseVowels(s);
}