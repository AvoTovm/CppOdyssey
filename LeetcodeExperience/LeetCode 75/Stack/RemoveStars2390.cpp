#include<iostream>
#include<string>

using namespace std;

string removeStars(string s) {
    string stack = "";

    for(char c : s){
        if(c == '*'){
            stack.pop_back();
        }else{
            stack += c;
        }
    }

    return stack;
}

int main(){
    string s = "leet**cod*e";

    cout<<removeStars(s);
}