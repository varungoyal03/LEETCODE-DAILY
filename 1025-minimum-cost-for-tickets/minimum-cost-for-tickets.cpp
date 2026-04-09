class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> travel(366, false);
        for (int d : days) travel[d] = true;

        vector<int> dp(367, 0);

        for (int day = 365; day >=0; day--) {
            if (!travel[day]) {
                dp[day] = dp[day +1];
            } else {

                dp[day] = min({
                    dp[day + 1] + costs[0],
                    dp[min(366, day +7)] + costs[1],
                    dp[min(366, day + 30)] + costs[2]
                });
            }
        }

        return dp[1];
    }
};