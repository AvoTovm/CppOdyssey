#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.length() + 1, false);
    dp[s.length()] = true;

    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    for (int i = s.length() - 1; i >= 0; --i) {
        for (const auto &w : wordSet) {
            if (i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
                dp[i] = dp[i + w.length()];
            }
            if (dp[i]) {
                break;
            }
        }
    }

    return dp[0];   
}

