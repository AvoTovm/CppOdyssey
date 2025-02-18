#include <iostream>
#include <vector>
using namespace std;

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size(); //row
        if(n == 0){
            return 0;
        }

        for(int i = n - 2 ; i >= 0; i--){
            for(int j = 0; j <= triangle[i].size() ; j++){
                triangle[i][j] = min(triangle[i + 1][j + 1] + triangle[i][j], triangle[i + 1][j] + triangle[i][j]);
            }
        }

        return triangle[0][0];
    }   


int main() {
    
    std::vector<std::vector<int>> grid = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout<<minimumTotal(grid);
    
}
