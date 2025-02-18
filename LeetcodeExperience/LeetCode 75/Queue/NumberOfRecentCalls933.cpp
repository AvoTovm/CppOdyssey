#include<queue>
using namespace std;

class RecentCounter {
    queue<int> timestamps;
public:
    RecentCounter() {}
    
    int ping(int t) {
        timestamps.push(t);

        while(!timestamps.empty() && timestamps.front() < t - 3000){
            timestamps.pop();
        }

        return timestamps.size();
    }
};
