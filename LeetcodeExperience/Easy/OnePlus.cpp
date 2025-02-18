#include <string>
#include <iostream>
#include <vector>
using namespace std;



    vector<int> plusOne(vector<int>& digits){
        int n = digits.size();
        digits[n] = digits[n] + 1;
        for(int k = 0; k < 1; k++){
            for(int i = 0; i < n; i++){
                if(digits[i] == 10){
                digits[i] = 0;
                digits[i - 1] = digits[i - 1] + 1;
                k = 0;
                }
            }
        }
        return digits;
    }

