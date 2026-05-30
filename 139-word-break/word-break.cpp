class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words(wordDict.begin(), wordDict.end());
        int n=s.size();
        vector<bool> dp(s.size() + 1, false);

        dp[n] = true;
        for (int i = n-1; i >=0; i--) {
            for (int j = i; j < n; j++) {
                if (dp[j+1] && words.count(s.substr(i, j-i+1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};