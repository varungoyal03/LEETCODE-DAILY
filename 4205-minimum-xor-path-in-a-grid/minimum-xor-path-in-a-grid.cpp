class Solution {
public:
    int minCost(vector<vector<int>>& g) {

           
        int m = g.size();
        int n = g[0].size();
        
        int MAX_XOR=1024; 

        bool dp[m][n][MAX_XOR];
        memset(dp, false, sizeof(dp));

    dp[0][0][g[0][0]]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0) for (int k=0;k<MAX_XOR;k++) dp[i][j][  k^g[i][j] ] |=dp[i-1][j][k];
                if(j>0) for (int k=0;k<MAX_XOR;k++) dp[i][j][  k^g[i][j] ] |=dp[i][j-1][k];
            

            }
        }
        
        for(int k=0;k<MAX_XOR;k++){
            if(dp[m-1][n-1][k]) return k;
        }

return -1;
    }
};