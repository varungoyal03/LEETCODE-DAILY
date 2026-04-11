class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums)
            total += x;

        int r = ((total % p) + p) % p;
        if (r == 0)
            return 0;

        map<int, int> mpLast;
        mpLast[0] = -1;
        long long prefixSum = 0;
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int curr = ((prefixSum % p) + p) % p;
            int needed = (curr - r + p) % p;

            if (mpLast.count(needed)) {
                ans = min(ans, i - mpLast[needed]);
            }

            mpLast[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};