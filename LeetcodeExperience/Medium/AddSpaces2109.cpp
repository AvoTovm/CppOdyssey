#include<iostream>
#include<vector>
#include<string>

using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    int k = spaces.size();

    string res = "";
    int j = 0;

    for(int i = 0; i < k; i++){
        
        if(i != k){}
        res += s.substr(j, spaces[i] - j) + ' ';
        j = spaces[i];
    }
    
    res += s.substr(j);
    return res ;
}

int main(){
    string s = "spacing";
    vector<int> spaces = {0,1,2,3,4,5,6};

    cout<<addSpaces(s,spaces);
}