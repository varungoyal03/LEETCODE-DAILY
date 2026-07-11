

class Solution {
public:
    // Helper function: Binary Search to find the NEXT interval in the future
    // that starts after (or exactly when) the current interval ends.
    int findNextCompatible(const vector<vector<int>>& intervals, int current_index) {
        int left = current_index + 1;
        int right = intervals.size() - 1;
        int n = intervals.size();
        
        int result = n; // Default to 'n' (our dummy out-of-bounds 0-value state)
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If the interval at 'mid' starts after or when 'current' ends
            if (intervals[mid][0] >= intervals[current_index][1]) {
                result = mid;    // This is valid! Lock it in.
                right = mid - 1; // But try to find a meeting that starts even SOONER
            } else {
                // It overlaps! We need to look further into the future
                left = mid + 1; 
            }
        }
        return result;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // 1. Sort strictly by START Time
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        
        // dp[i] stores the max non-overlapping intervals from index 'i' to the end.
        // Size is n + 1. dp[n] is natively 0, representing the "end of time".
        vector<int> dp(n + 1, 0);
        
        // 2. Build the DP table from Right-to-Left (Future to Present)
        for (int i = n - 1; i >= 0; i--) {
            
            // OPTION A: Leave It
            // Just take the best score from the timeline directly to our right
            int leave_it = dp[i + 1];
            
            // OPTION B: Take It
            // 1 (for current meeting) + best score from the next compatible meeting
            int next_valid_idx = findNextCompatible(intervals, i);
            int take_it = 1 + dp[next_valid_idx];
            
            // The DP State: Take the maximum of both choices
            dp[i] = max(leave_it, take_it);
        }
        
        // Total intervals minus the maximum valid intervals we can keep starting from 0
        return n - dp[0];
    }
};