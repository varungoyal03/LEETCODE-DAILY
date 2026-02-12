class Solution {
public:
    int longestBalanced(string s) {
        const int n = (int)s.length();
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int maxCount = 0;
            int numDistinct = 0;
            vector<int> count(26, 0);
            for (int j = i; j < n; j++) {
                numDistinct += count[s[j] - 'a'] == 0;
                maxCount = max(maxCount, ++count[s[j] - 'a']);
                if (maxCount * numDistinct == j - i + 1)
                    ans = max(ans, j - i + 1);
            }
        }
        
        return ans;
    }
};