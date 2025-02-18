#include<iostream>
#include<vector>

using namespace std;


long long minEnd(int n, int x) {
    long long res = x;

    for(int i = 1 ; i < n; i++){
        res = (res + 1) | x;
    }

    return res;
}

int main(){

    int n = 6715154;
    int x = 7193485;

    cout<<minEnd(n,x);

}