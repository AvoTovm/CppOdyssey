#include<iostream>
#include<vector>
#include<string>

using namespace std;

int compress(vector<char>& chars) {
    int k = chars.size();

    string s;

    char temp = chars[0];
    int count = 1;;
    for(int i = 1; i < k; i++){
        if(chars[i] != temp){
            s += temp;

            if(count > 1){
                s += to_string(count); 
            }

            temp = chars[i];
            count = 1;
        }else{
            count++;
        }

    }
    s += temp;
    if (count > 1) {
        s += to_string(count);
    }
    
    chars.clear();
    for (char c : s) {
        chars.push_back(c);
    }

    return s.size();
    
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};

    cout<<compress(chars);
}