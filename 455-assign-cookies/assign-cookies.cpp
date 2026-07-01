class Solution {
public:
// If the cookie is too small (s[j] < g[i]), we can't use it for this child (and therefore, we can't use it for any child after them either, since they are even greedier). Just move to the next cookie
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int kidIndex = 0; // Our single pointer tracking the children
        
        // 2. Use the for-loop to iterate through the cookies
        for (int i = 0; i < s.size(); i++) {
            
            // Optimization: If we ran out of kids, stop checking cookies
            if (kidIndex == g.size()) {
                break;
            }
            
            // If the current cookie (s[i]) is large enough for the current kid
            if (s[i] >= g[kidIndex]) {
                kidIndex++; // The kid is happy! Move to the next kid.
            }
        }
        
        // Because kidIndex started at 0 and only moved when a kid got a cookie,
        // it holds the exact number of content children!
        return kidIndex;
    }
};