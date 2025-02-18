#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> count;

    for(const auto& row : matrix){
        string row_key;
        bool flip = row[0] == 1;

        for(int num : row){
            row_key += (flip ? '0' + (1 - num) : '0' + num); // Flip or keep as is
        }

        count[row_key]++;
    }

    int max_count = 0;
    for(const auto& [key, value] : count){
        max_count = max(max_count, value);
    }

    return max_count;
}
