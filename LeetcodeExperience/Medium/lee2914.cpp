#include<iostream>

using namespace std;

int minChanges(string s) {

        long long count = 0;
        int i = 0;

        while (i < s.size()) {
            if (s[i] != s[i + 1]) {
                count++;
                i += 2;
            }else{
                i += 2;
            }
        }

        return count;
    }