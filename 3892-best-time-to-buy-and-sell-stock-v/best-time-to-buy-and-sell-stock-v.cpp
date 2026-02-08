class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
  //dp[i][k][3] 0 3 0
  int n = prices.size();

        // dp[k][state]
        // state: 0 = settled (no position)
        //        1 = buy (holding long)
        //        2 = short (holding short)
        vector<vector<long long>> dp(K + 1, vector<long long>(3, 0));
        vector<vector<long long>> next = dp;
        const long long NEG = -1e17;
        for (int k = 0; k <= K; k++) {
            next[k][1] = next[k][2] = NEG;//
}

        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=K;k++ ){//if k==0 if we cant do anything
                
                dp[k][0]=max({next[k][0],-prices[i]+next[k][2],prices[i]+next[k][1]});
                dp[k][1]=max({ next[k][1],-prices[i]+next[k-1][0]});
                 dp[k][2]=max({ next[k][2],prices[i]+next[k-1][0]});



            }

            next=dp;
        }

return next[K][0];
    }
};