class Solution {
public:
    int find(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
        
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return  dp[i][j]=1 + find(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] =
                   max(find(i, j - 1, s1, s2, dp), find(i - 1, j, s1, s2, dp));
    }
    int longestCommonSubsequenceTABULATION(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (s1[i] == s2[j])
                    dp[i+1][j+1] = 1 + dp[i][j ];
                else    
                dp[i+1][j+1] = max(dp[i+1][j ], dp[i ][j+1]);
            }
        }
       return dp[n][m];

    }

        int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
         vector<int>  curr(m+1, 0);
         vector<int>  prev(m+1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (s1[i] == s2[j])
                    curr[j+1] = 1 + prev[j];
                else    
                curr[j+1] = max(curr[j ], prev[j+1]);
            }
            prev=curr;
        }
       return prev[m];

    }
};