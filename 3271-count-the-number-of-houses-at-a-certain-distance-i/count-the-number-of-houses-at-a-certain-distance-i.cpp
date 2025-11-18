class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
         for(int i=1;i<=n;i++) dp[i][i]=0;

        for(int i=1;i<n;i++){
            
            dp[i][i+1]=1;
            dp[i+1][i]=1; //
        }
        if(x!=y){
        dp[x][y]=1;
        dp[y][x]=1;}

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(dp[i][k]==INT_MAX) continue;
                for(int j=1;j<=n;j++){
                        if(dp[k][j]==INT_MAX) continue;

                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }


         vector<int> result(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {

                if(i != j) {
                    int val = dp[i][j];
                    result[val-1]++;
                }

            }
        }
        
        return result;



    }
};