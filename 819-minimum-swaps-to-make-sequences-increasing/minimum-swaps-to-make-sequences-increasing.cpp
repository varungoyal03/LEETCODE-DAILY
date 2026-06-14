

class Solution {
    vector<vector<int>> dp;

    // This function now STRICTLY handles i >= 1
    int solveRec(int i, int swapped, vector<int>& nums1, vector<int>& nums2) {
        // 1. BASE CASE
        if (i == nums1.size()) {
            return 0;
        }

        // 2. MEMO CHECK
        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }

        int minSwaps = 1e9; // Start with infinity

        // 3. FIGURE OUT YESTERDAY (Clean and exact!)
        // Because i is guaranteed to be >= 1, we can just directly access i - 1.
        int prev1 = swapped ? nums2[i - 1] : nums1[i - 1];
        int prev2 = swapped ? nums1[i - 1] : nums2[i - 1];

        // 4. CHOICE 1: KEEP (Do not swap today)
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            minSwaps = min(minSwaps, solveRec(i + 1, 0, nums1, nums2));
        }

        // 5. CHOICE 2: SWAP (Swap today)
        if (nums2[i] > prev1 && nums1[i] > prev2) {
            // Add 1 because we are performing a swap
            minSwaps = min(minSwaps, 1 + solveRec(i + 1, 1, nums1, nums2));
        }

        return dp[i][swapped] = minSwaps;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        dp.assign(n, vector<int>(2, -1));
        
        // --- EXPLICITLY HANDLE INDEX 0 HERE ---
        
        // Option A: Do NOT swap at index 0. Cost is 0. Move to index 1.
        int keep_at_zero = solveRec(1, 0, nums1, nums2);
        
        // Option B: DO swap at index 0. Cost is 1. Move to index 1.
        int swap_at_zero = 1 + solveRec(1, 1, nums1, nums2);
        
        // Return the absolute best of the two branching realities
        return min(keep_at_zero, swap_at_zero);
    }
};