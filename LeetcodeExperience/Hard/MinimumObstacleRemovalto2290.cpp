#include <vector>
#include <queue>
#include <set>
#include <tuple> 
#include <utility> 
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({0, 0, 0});
        
        set<pair<int, int>> visited;
        visited.insert({0, 0});

        while (!minHeap.empty()) {
            auto [obstacles, r, c] = minHeap.top();
            minHeap.pop();

            if (r == ROWS - 1 && c == COLS - 1) {
                return obstacles;
            }

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || visited.count({nr, nc})) {
                    continue;
                }

                minHeap.push({obstacles + grid[nr][nc], nr, nc});
                visited.insert({nr, nc});
            }
        }

        return -1;
    }
};
