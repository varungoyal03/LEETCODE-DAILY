class Solution {
public:
    vector<vector<long long>> dp;
    vector<int> cost;

    long long solve(int i, int end, int k) {
        // 🎯 Base cases

        // If we selected exactly k peaks
        if (k == 0) return 0;

        // If index crosses limit → not possible
        if (i > end) return LLONG_MAX;

        // Memo check
        if (dp[i][k] != -1) return dp[i][k];

        long long res = LLONG_MAX;

        // 🟡 Option 1: Skip current index
        long long skip = solve(i + 1, end, k);
        res = min(res, skip);

        // 🔵 Option 2: Take current index as peak
        long long take = solve(i + 2, end, k - 1);
        if (take != LLONG_MAX) {
            res = min(res, take + cost[i]);
        }

        return dp[i][k] = res;
    }

    long long eval(int start, int end, int k) {
        int n = cost.size();

        // dp[i][k] → min cost starting from index i selecting k peaks
        dp.assign(n + 2, vector<long long>(k + 1, -1));

        return solve(start, end, k);
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n / 2) return -1;
        if (k == 0) return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;

        cost.resize(n);

        // 🔥 Precompute cost
        for (int i = 0; i < n; i++) {
            int left = nums[(i - 1 + n) % n];
            int right = nums[(i + 1) % n];
            cost[i] = max(0, max(left, right) + 1 - nums[i]);
        }

        long long ans = LLONG_MAX;

        // ✅ Case 1: skip index 0
        ans = min(ans, eval(1, n - 1, k));

        // ✅ Case 2: take index 0
       
            long long val = cost[0] + eval(2, n - 2, k - 1);
            ans = min(ans, val);
        

        return ans ;
    }
};