#include<iostream>

using namespace std;

bool canMakeSubsequence(string str1, string str2){
    if(str2.size() > str1.size()) return false;

    int j = 0;

    for(int i = 0; i < str1.size(); i++){
        if(str1[i] == str2[j] || str1[i] == str2[j] - 1 || (str1[i] == 'z' && str2[j] == 'a')){
            j++;
        }
    }
    if(j == str2.size()){
        return true;
    }else{
        return false;
    } 
}

int main(){
    string s = "zc";
    string s2 = "ad";

    cout<<canMakeSubsequence(s,s2);
}