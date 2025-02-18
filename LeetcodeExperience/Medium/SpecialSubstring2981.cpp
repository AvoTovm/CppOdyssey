#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maximumLength(const std::string& s) {
    int best = -1;
    int N = s.length();

    for(char c = 'a'; c <= 'z'; c++){
        bool changed = true;
        int current = max(best + 1, 1);

        while(changed){
            int count = 0;
            changed = false;
            string now(current, c);

            for(int i = 0; i < N; i++){
                if(s.substr(i).find(now) == 0){
                    ++count;
                }
            }

            if(count >= 3){
                changed = true;
                best = max(best, current);
                ++current;
            }else{
                break;
            }
        }
    }

    return best;
}

int main() {
    string s = "aaaa";
    cout<<maximumLength(s);
}
