#include<iostream>

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true ;
    return false;
}

int maxVowels(string s, int k) {
    int maxVowels = 0;

    for(int i = 0; i < k; i++){
        if(isVowel(s[i])) maxVowels++;
    }

    int tempVowels = maxVowels;

    for(int i = 1; i < s.size() - k + 1; i++){
        if(isVowel(s[i - 1])){
            tempVowels--;
        }
        if(isVowel(s[i + k - 1])) tempVowels++;

        maxVowels = max(maxVowels, tempVowels);
        if(maxVowels == k) return k;
    }

    return maxVowels;
}

int main(){
    string s = "abciiidef";
    int k  = 3;

    cout<<maxVowels(s,k);
}