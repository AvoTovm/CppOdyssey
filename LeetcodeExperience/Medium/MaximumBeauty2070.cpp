#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end());

    vector<pair<int, int>> indexedVec;
    for (int i = 0; i < queries.size(); ++i) {
        indexedVec.push_back({i, queries[i]});
    }
    sort(indexedVec.begin(), indexedVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<vector<int>> new_q;
    for (const auto& pair : indexedVec) {
        new_q.push_back({pair.first, pair.second});
    }
    int k = queries.size();
    vector<int> res(k, 0);

    int max_b = 0;
    int j = 0;

    for(auto& t: new_q){
        int q = t[1];
        int i = t[0];

        while(j < items.size() && items[j][0] <= q){
            max_b = max(max_b, items[j][1]);
            j++;
        }

        res[i] = max_b;
    }

    for(int i = 0; i< res.size(); i++){
        cout<<res[i]<<" ";
    }

    return res;
}

int main(){
    vector<vector<int>> items = {{1,2}, {3,2}, {2,4}, {5,6}, {3,5}};

    vector<int> queri = {1,2,6,5,3,4};

    maximumBeauty(items, queri);

}