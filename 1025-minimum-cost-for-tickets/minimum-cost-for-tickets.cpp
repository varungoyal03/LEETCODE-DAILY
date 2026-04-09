class Solution {
public:
vector<int> time={1,7,30};
 vector<int> dp;

    int solve(int i,vector<int>& days, vector<int>& costs){
        int n=days.size();
        if(i==days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int cost1 = costs[0] + solve(i + 1, days, costs);

         int j = i;
        while (j < n && days[j] <= days[i] + 6) j++;
        int cost7 = costs[1] + solve(j, days, costs);

        int k = i;
        while (k < n && days[k] <= days[i] + 29) k++;
        int cost30 = costs[2] + solve(k, days, costs);


           return dp[i] = min({cost1, cost7, cost30});


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
       dp.assign(n+1,-1);
        return solve(0,days,costs);
        
    }
};
