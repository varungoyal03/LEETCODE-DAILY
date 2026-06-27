
class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.size();
        if (n == 0) return 0;
        
        // This stack will hold the INDICES of unmatched '('
        stack<int> s;
        
        // This array acts as a boolean map to flag valid pairs.
        // 0 means invalid/unmatched, 1 means part of a valid pair.
        vector<int> isValid(n, 0); 
        
        // ---------------------------------------------------------
        // PHASE 1: Find all valid pairs and flag their indices
        // ---------------------------------------------------------
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                // We found an open parenthesis, push its index to wait for a match
                s.push(i);
            } 
            else if (!s.empty()) {
                // We found a close parenthesis AND we have a waiting open parenthesis!
                int matched_position = s.top();
                s.pop();
                
                // Flag both the open and close positions as '1' (Safe Zone)
                isValid[matched_position] = 1;
                isValid[i] = 1;
            }
        }
        
        // ---------------------------------------------------------
        // PHASE 2: Find the longest contiguous streak of 1s
        // ---------------------------------------------------------
        int current_streak = 0;
        int max_streak = 0;
        
        for (int i = 0; i < n; i++) {
            if (isValid[i] == 1) {
                // Continue the streak
                current_streak++;
            } else {
                // We hit an unmatched parenthesis (a 0). The streak is broken!
                current_streak = 0;
            }
            
            // Constantly track the highest streak we have seen
            max_streak = max(max_streak, current_streak);
        }
        
        return max_streak;
    }
};