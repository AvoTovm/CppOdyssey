#include <vector>
using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> incoming(n, 0);

    // Update the incoming counts for each node
    for (const auto& edge : edges) {
        int src = edge[0];
        int dst = edge[1];
        incoming[dst]++;
    }

    vector<int> champions;

    // Find nodes with no incoming edges
    for (int i = 0; i < n; ++i) {
        if (incoming[i] == 0) {
            champions.push_back(i);
        }
    }

    // If there are multiple champions, return -1
    if (champions.size() > 1) {
        return -1;
    }

    // Return the single champion if it exists, otherwise -1
    return champions.empty() ? -1 : champions[0];
}
