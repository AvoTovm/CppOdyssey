#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

double gain(int pass, int total) {
    return (double)(pass + 1) / (total + 1) - (double)pass / total;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, pair<int, int>>> maxHeap;

    for(auto& c : classes){
        int pass = c[0], total = c[1];
        maxHeap.push({gain(pass, total), {pass, total}});
    }


    for(int i = 0; i < extraStudents; ++i){
        auto top = maxHeap.top();
        maxHeap.pop();
        int pass = top.second.first;
        int total = top.second.second;

        ++pass;
        ++total;

        maxHeap.push({gain(pass, total), {pass, total}});
    }

    double totalSum = 0;
    while (!maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();
        int pass = top.second.first;
        int total = top.second.second;
        totalSum += (double)pass / total;
    }

    return totalSum / classes.size();
}

int main() {
    vector<vector<int>> classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    int extraStudents = 4;

    cout << maxAverageRatio(classes, extraStudents);
}
