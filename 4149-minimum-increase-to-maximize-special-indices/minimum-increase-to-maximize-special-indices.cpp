class Solution {
public:
    vector<vector<long long>> dp;
    vector<int> nums;

    long long dfs(int i, int j) {
        if (i <= 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long cost = max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);

        long long res = dfs(i - 2, j) + cost;

        if (j) {
            res = min(res, dfs(i - 1, 0));
        }

        return dp[i][j] = res;
    }

    long long minIncrease(vector<int>& arr) {
        nums = arr;
        int n = nums.size();

        int k = (n % 2 == 0); // allow one skip if even

        dp.assign(n, vector<long long>(2, -1));

        return dfs(n - 2, k);
    }
};