#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> out_degree, in_degree;

    for (const auto& pair : pairs) {
        int u = pair[0], v = pair[1];
        graph[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
    }

    int start = pairs[0][0];
    for (const auto& [node, _] : graph) {
        if (out_degree[node] > in_degree[node]) {
            start = node;
            break;
        }
    }

    vector<int> path;
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int u = stk.top();
        if (!graph[u].empty()) {
            int v = graph[u].back();
            graph[u].pop_back();
            stk.push(v);
        } else {
            path.push_back(u);
            stk.pop();
        }
    }

    reverse(path.begin(), path.end());

    vector<vector<int>> result;
    for (int i = 0; i < path.size() - 1; ++i) {
        result.push_back({path[i], path[i + 1]});
    }

    return result;
}

int main() {
    vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    auto result = validArrangement(pairs);

    for (const auto& pair : result) {
        cout << pair[0] << " -> " << pair[1] << endl;
    }
    return 0;
}
