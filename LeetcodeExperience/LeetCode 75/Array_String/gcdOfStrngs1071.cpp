#include<iostream>

using namespace std;

string gcdOfStrings(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    for(int i = min(m,n) - 1; i >= 0; i--){
        if(m % i == 0 && n % i == 0){
            string temp = str1.substr(0, i);
            string temp1 = "";
            string temp2 = "";

            for (int j = 0; j < m / i; j++) temp1 += temp;
            for (int j = 0; j < n / i; j++) temp2 += temp;

            if (temp1 == str1 && temp2 == str2) {
                return temp;
            }
        }
    }
    return "";
}

int main(){
    string a = "ababab";
    string b = "abab";

    cout<<gcdOfStrings(a,b);
}