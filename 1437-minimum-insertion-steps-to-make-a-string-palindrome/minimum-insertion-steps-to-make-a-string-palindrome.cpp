class Solution {
public:
 int longestPalindromeSubseq(string s1) {
        
        string s2=s1;
        reverse(s2.begin(),s2.end());

        int n = s1.size();
        int m = s2.size();
         vector<int>  curr(m+1, 0);
         vector<int>  prev(m+1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (s1[i] == s2[j])
                    curr[j+1] = 1 + prev[j];
                else    
                curr[j+1] = max(curr[j ], prev[j+1]);
            }
            prev=curr;
        }
       return prev[m];
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};