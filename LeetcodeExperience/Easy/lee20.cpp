#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, char> closeBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    stack<char> stack;

    for (char c : s){
        if (closeBrackets.count(c)){
            if (!stack.empty() && stack.top() == closeBrackets[c]){
                stack.pop();
            }
            else{
                return false;
            }
        }
        else{
            stack.push(c);
        }
    }

    return stack.empty();
};

int main(){

    string s = "{[()]}";
    
    if(isValid(s)){
        cout<<"True"<<"\0";
    }else{
        cout<<"False"<<"\0";
    }

}