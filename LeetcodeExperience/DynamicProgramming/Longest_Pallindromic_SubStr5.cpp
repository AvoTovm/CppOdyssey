#include <iostream>
#include <cstring>

using namespace std;

string longestPalindrome(string s) {
        string Result = "";
        int resultLenght = 0;

        for(int i = 0; i < s.size(); i++){

            //odd lenght
            int l = i;
            int r = i;

            while(l >= 0 && r <s.size() && s[l] == s[r]){
                if((r - l + 1) > resultLenght){
                    Result = s.substr(l, r - l + 1);
                    resultLenght = r - l + 1;
                }
                l--;
                r++;
            }

            //even lenght
            l = i;
            r = i + 1;   

            while(l >= 0 && r <s.size() && s[l] == s[r]){
                if((r - l + 1) > resultLenght){
                    Result = s.substr(l, r - l + 1);
                    resultLenght = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return Result;
    }


int main(){
    string p = "babaddtattarrattatddetartrateedredividerb";

    cout<<longestPalindrome(p);
}