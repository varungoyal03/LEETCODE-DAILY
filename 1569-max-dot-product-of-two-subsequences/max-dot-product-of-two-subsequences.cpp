class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // Size [m+1][n+1] allows us to safely look at i+1 and j+1.
        // We fill the entire board with Negative Infinity to handle our boundary base cases!
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1e9));

        // Loop BACKWARDS from the end of both arrays
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                int val = nums1[i] * nums2[j];

                // Option 1: Take both. Sever the tie if the future is negative.
                int takeBoth = val + max(0, dp[i + 1][j + 1]);
                
                // Option 2 & 3: Skip
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                // Store the maximum of the 3 choices
                dp[i][j] = max({takeBoth, skip1, skip2});
            }
        }

        // The answer bubbles all the way up to the Top-Left anchor
        return dp[0][0];
    }
};