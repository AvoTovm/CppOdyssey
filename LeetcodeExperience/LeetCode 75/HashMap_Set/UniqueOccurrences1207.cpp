#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<utility>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map;

    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    unordered_set<int> unique;

    for(auto it = map.begin(); it != map.end(); ++it){
    int value = it->second;
    if(unique.count(value)){
        return false;
    }
    unique.insert(value);
    }

    return true;

}

int main(){
    vector<int> nums = {1,2,2,1,1,3};

    cout<<uniqueOccurrences(nums);
}