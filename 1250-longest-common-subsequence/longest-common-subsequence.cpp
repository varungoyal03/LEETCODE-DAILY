class Solution {
public:
    int find(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return dp[i+1][j+1]=0;
        if (dp[i+1][j+1] != -1)
            return dp[i+1][j+1];

        if (s1[i] == s2[j])
            return  dp[i+1][j+1]=1 + find(i - 1, j - 1, s1, s2, dp);

        return dp[i+1][j+1] =
                   max(find(i, j - 1, s1, s2, dp), find(i - 1, j, s1, s2, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {

        //         if (s1[i] == s2[j])
        //             dp[i][j] = 1 + dp[i - 1][j - 1];

        //         dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        //     }
        // }
       return find(n-1,m-1,s1,s2,dp);

    }
};