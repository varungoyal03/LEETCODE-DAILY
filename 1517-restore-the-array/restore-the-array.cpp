class Solution {
public:
int MOD=1e9+7;
    vector<int> dp;
    int solve(int i, string& s, int& k) {
        if (i == s.size())
            return dp[i] = 1;

        if (s[i] == '0')
            return dp[i] = 0;

        if (dp[i] != -1)
            return dp[i];

        long long ans = 0 ; 
        long long  num = 0;//
        for (int start = i; start < s.size(); start++) {
            num = num * 10 + s[start] - '0';

            if (num > k)
                break;
            ans = (ans%MOD +solve(start + 1, s, k)%MOD  )%MOD;
        }

        return dp[i] = ans;
    }
    int numberOfArrays(string s, int k) {
        dp.assign(s.size() + 1, -1);
        return solve(0, s, k);
    }
};