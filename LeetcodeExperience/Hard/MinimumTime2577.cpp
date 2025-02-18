#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

int minimumTime(vector<vector<int>>& grid) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    if(min(grid[0][1], grid[1][0]) > 1){
        return -1;
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    minHeap.emplace(0, 0, 0);
    set<pair<int, int>> visited;

    while(!minHeap.empty()){
        auto [t, r, c] = minHeap.top();
        minHeap.pop();

        if(r == ROWS - 1 && c == COLS - 1){
            return t;
        }

        vector<pair<int, int>> neighbors = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for(auto [nr, nc] : neighbors){
            if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || visited.count({nr, nc})){
                continue;
            }
            int wait = 0;
            if(abs(grid[nr][nc] - t) % 2 == 0){
                wait = 1;
            }
            int n_time = max(grid[nr][nc] + wait, t + 1);

            minHeap.emplace(n_time, nr, nc);
            visited.emplace(nr, nc);
        }
    }
}

