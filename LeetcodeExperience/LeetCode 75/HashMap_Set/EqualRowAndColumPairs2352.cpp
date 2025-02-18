#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int m = grid.size();

    unordered_map<string, int> rowMap;
    string temp = "";


    for(int i = 0; i < m; i++){
        temp = "";
        for(int j = 0; j < m; j++){
            temp += to_string(grid[i][j]) + ",";
        }
        rowMap[temp]++;
    }

    int res = 0;

    for(int j = 0; j < m; j++){
        temp = "";
        for(int i = 0; i < m; i++){
            temp += to_string(grid[i][j]) + ",";
        }
        res += rowMap[temp];
    }

    return res;
}

int main(){
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout<<equalPairs(grid);
}