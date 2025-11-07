class Solution {
public:
    int dp[32][2][2];  // dp[pos][tight][prevOne]

    int solve(string &s, int idx, bool tight, bool prevOne) {
        if (idx == s.size()) 
            return 1;  // Base case: return total 1s counted so far

        if (dp[idx][tight][prevOne] != -1) 
            return dp[idx][tight][prevOne];

        int lb = 0;
        int ub = tight ? (s[idx] - '0') : 1;//

        int res = 0;

        for (int dig = lb; dig <= ub; dig++) {


            if(dig==1 && prevOne) continue; 
            res += solve(s, idx + 1, (tight && dig == ub), (dig==1 ) );
        }

        return dp[idx][tight][prevOne] = res;
    }

    int findIntegers(int n) {


    string s;
        if (n == 0) s="0";
    while (n) {
        s.push_back((n & 1) + '0');  // extract last bit
        n >>= 1;                     // shift right (drop the bit)
    }
    reverse(s.begin(), s.end());


        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, false);
    }
};



