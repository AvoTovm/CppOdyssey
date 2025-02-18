#include<iostream>
#include<string>

using namespace std;

string makeFancyString(string s) {
    int k = s.size();

    string result = "";
    result += s[0];
    int count = 1;

    for(int i = 1; i < k; i++){
        if(s[i] != s[i - 1] || count < 2){
            result += s[i];
            if(s[i] == s[i - 1]){
                count++;
            }else{
                count = 1;
            }
        }
    }

    return result;
}

int main(){
    string a = "aaaabba";

    cout<<makeFancyString(a);
}