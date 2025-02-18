#include<vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
        int currentAltitude;
        int maxAltitude = 0;

        for(int i = 0 ; i < gain.size(); i++){
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
}