#include <string>
#include <iostream>
using namespace std;


    int main(){
        string s = {"IIIV"};

        int k = s.length();
        int c = 0;

        for(int i = 0; i < k; i++){
            if(s[i] == 'I'){
                if(s[i + 1] == 'X'){
                    c = c + 9;
                    i++;
                }else if(s[i + 1] == 'V'){
                    c = c + 4;
                    i++;
                }else{
                    c = c + 1;
                }
            }else if(s[i] == 'V'){
                c = c + 5;  
            }else if(s[i] == 'X'){
                if(s[i + 1] == 'L'){
                    c = c + 40;
                    i++;
                }else if(s[i + 1] == 'C'){
                    c = c + 90;
                    i++;
                }else{
                    c = c + 10;
                }
            }else if(s[i] == 'L'){
                c = c + 50;  
            }else if(s[i] == 'C'){
                if(s[i + 1] == 'D'){
                    c = c + 400;
                    i++;
                }else if(s[i + 1] == 'M'){
                    c = c + 900;
                    i++;
                }else{
                    c = c + 100;
                }
            }else if(s[i] == 'D'){
                c = c + 500;  
            }else if(s[i] == 'M'){
                c = c + 1000;
            }
        }
        cout<<c;

    }