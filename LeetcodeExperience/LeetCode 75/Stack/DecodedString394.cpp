#include<iostream>
#include<stack>
#include<string>

using namespace std;

string decodeString(string s) {
    stack<int> counts;
    stack<string> strings;

    string res = "";
    int k = 0;

    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            k = k * 10 + (s[i] - '0');
        }else if(s[i] == '['){
            counts.push(k);
            strings.push(res);
            res = "";
            k = 0;
        }else if(s[i] == ']'){
            string temp = res;
            int count = counts.top();
            counts.pop();
            res = strings.top();
            strings.pop();
            while(count-- > 0){
                res += temp;
            }
        }else{
            res += s[i];
        }
    }

    return res;
}

int main(){
    string s = "3[a2[c]]";

    cout<<decodeString(s);
}