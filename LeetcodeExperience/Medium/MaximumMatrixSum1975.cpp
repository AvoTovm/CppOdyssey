#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long k = matrix.size();
    stack<int> negative;

    long long minNum = 100000;
    long long res = 0;

    for(long long i = 0; i < k; i++){
        for(long long j = 0; j < k; j++){
            if(matrix[i][j] < 0 && negative.empty()){
                negative.push(1);
            }else if(matrix[i][j] < 0 && !negative.empty()){
                negative.pop();
            }
            long long value = matrix[i][j];
            res += abs(value);

            minNum = min(minNum, abs(value));
        }
    }

    if(!negative.empty()){
        res -= 2 * minNum;
    }

    return res;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};

    cout<<maxMatrixSum(matrix);
}