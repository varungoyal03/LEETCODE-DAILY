class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
         int n = s1.size();
    int m = s2.size();

    // dp table size [n+1][m+1] initialized to 0.
    // The n-th row and m-th column are our '0' base cases!
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Loop backwards: Because solve(i) needs solve(i+1)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            
            // EXACT copy-paste from recursion
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
            
        }
    }

    // Since we looped down to 0, the final answer sits at the starting indices
    return dp[0][0];
    }
};