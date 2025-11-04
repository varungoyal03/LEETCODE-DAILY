class Solution {
public:
    // long long and  if (s[i] == '0') aryan
    int MOD = 1e9 + 7;
    vector<int> dp;
    int solveMEMO(int i, string& s, int& k) {
        if (i == s.size())
            return dp[i] = 1;

        if (s[i] == '0')
            return dp[i] = 0;

        if (dp[i] != -1)
            return dp[i];

        long long ans = 0;
        long long num = 0; //
        for (int start = i; start < s.size(); start++) {
            num = num * 10 + s[start] - '0';

            if (num > k)
                break;
            ans = (ans % MOD + solveMEMO(start + 1, s, k) % MOD) % MOD;
        }

        return dp[i] = ans;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.assign(n + 1, -1);
        // return solveMEMO(0, s, k);

        dp[n] = 1;


        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            long long ans = 0;
            long long num = 0; //
            for (int start = i; start < n; start++) {
                num = num * 10 + s[start] - '0';

                if (num > k)
                    break;

                ans = (ans % MOD + dp[start + 1] % MOD) % MOD;
                
            }
            dp[i] = ans;//forgot
        }


        return dp[0];
    }
};