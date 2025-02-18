#include <vector>
#include <iostream>
using namespace std;

class MyHashMap {
public:
    vector<vector<pair<int, int>>> map;  

    int hash(int key) {
        return key % map.size(); 
    }

    MyHashMap() : map(1000) {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto& pair : map[h]) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }
        }
        map[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (const auto& pair : map[h]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = map[h].begin(); it != map[h].end(); ++it) {
            if (it->first == key) {
                map[h].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap hashMap;

    hashMap.put(1, 1);
    hashMap.put(2, 2);

    cout << "Get 1 " << hashMap.get(1) << "\n";  
    cout << "Get 2 " << hashMap.get(2) << "\n";  
    cout << "Get 3 " << hashMap.get(3) << "\n"; 

    hashMap.put(2, 20);
    cout << "Get 2 " << hashMap.get(2) << "\n";

    hashMap.remove(2);
    cout << "Get 2 after removal " << hashMap.get(2) << "\n";

    return 0;
}
