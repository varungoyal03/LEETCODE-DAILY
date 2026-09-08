class Solution {
public:
typedef long long ll;
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> dp(26, 0);//countEndWith[idx] 

        ll total = 0;

        for(int i = 0; i < n; i++){
            int chIdx = s[i] - 'a';

            // Create new subsequences and remove duplicates
            int add = (1 + total - dp[chIdx] + MOD) % MOD;

            dp[chIdx]=1 + total ;
            total = (total + add) % MOD;
        }

        return total;
    }
};