class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e8));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // if (nums1[i] * nums2[j] > 0) {
                    
                    dp[i + 1][j + 1] =
                        max({nums1[i] * nums2[j] ,nums1[i] * nums2[j]  + dp[i][j], dp[i + 1][j], dp[i][j + 1]});
               
            }
        }
        return dp[n][m];
    }
};