#include<vector>
#include<unordered_map>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    if (n == 1 && trust.empty()) return 1;

    int k = trust.size();

    unordered_map<int , int> incoming;
    unordered_map<int , int> outgoing;


    for(const auto& t : trust){
        int a = t[0];
        int b = t[1];

        outgoing[a]++;
        incoming[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(outgoing[i] == 0 && incoming[i] == n - 1){
            return i;
        }
    }

    return -1;
}