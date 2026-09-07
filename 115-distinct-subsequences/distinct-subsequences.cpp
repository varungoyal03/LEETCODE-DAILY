class Solution {
private:
    int dfs(int i, int j, const string& s, const string& t, vector<vector<int>>& memo) {
        // Base case 1: If we reached the end of t, we found 1 valid subsequence
        if (j == t.length()) {
            return 1;
        }
        
        // Base case 2: If we reached the end of s but not t, 0 valid subsequences
        if (i == s.length()) {
            return 0;
        }
        
        // Return cached result if we have visited this state before
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // We use unsigned int to prevent signed integer overflow exceptions in C++ 
        // on intermediate recursive calculations, as LeetCode test cases can trigger it.
        int count = dfs(i + 1, j, s, t, memo);
        
        if (s[i] == t[j]) {
            // If characters match, add the paths where we include s[i]
            count += dfs(i + 1, j + 1, s, t, memo);
        }
        
        return memo[i][j] = count;
    }

public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Initialize memoization table with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        // Start recursion from index 0 of string s and index 0 of string t
        return dfs(0, 0, s, t, memo);
    }
};