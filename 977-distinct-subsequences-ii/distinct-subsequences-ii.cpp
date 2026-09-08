class Solution {
public:
typedef long long ll;
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> dp(26, 0);//countEndWith[idx] 

        ll curr = 1;

        for(int i = 0; i < n; i++){
            int chIdx = s[i] - 'a';

            // Create new subsequences and remove duplicates
            ll temp=curr;
            curr = (curr*2 - dp[chIdx] + MOD) % MOD;

            dp[chIdx]=temp ;
    
        }

        return (curr-1 +MOD) % MOD;
    }
};