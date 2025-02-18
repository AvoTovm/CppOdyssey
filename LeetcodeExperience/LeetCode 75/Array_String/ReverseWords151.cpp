#include<iostream>

using namespace std;

string reverseWords(string s) {
    string res;

    int l = s.size() - 1;
    int r = s.size() - 1;

    while(l >= 0 ){
        while(l >= 0 && s[l] == ' '){
            l--;
        }
        r = l;
        while(l >= 0 && s[l] != ' '){
            l--;
        }

        res += s.substr(l + 1, r - l) + ' ';

        while(l >= 0 && s[l] == ' '){
            l--;
        }
        r = l;
    }
    if (!res.empty() && res.back() == ' ')
        res.pop_back();


    return res;
}

int main(){
    string s = "  hello world  ";

    cout<<reverseWords(s);

}