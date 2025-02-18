#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> Doubles;

    for(int  i = 0; i < arr.size(); i++){
        
        if(Doubles.find(arr[i] * 2) != Doubles.end()){
            return true;
        }
        if(arr[i] % 2 == 0 && Doubles.find(arr[i] / 2) != Doubles.end()){
            return true;
        }
        Doubles[arr[i]] = i;
    }

    return false;
}

int main(){
    vector<int> arr = {10 , 2, 5, 7};

    cout<<checkIfExist(arr);
}