class Solution {
public:
int MOD=1e9 +7;
  vector<vector<int>> dp;
    int solve(int i,int k,int sum){
        if(i==0)  return sum==0;
if(dp[i][sum]!=-1) return dp[i][sum];
        int totalWays=0;
        for(int face=1;face<=k;face++){
            if(sum>=face) totalWays=(totalWays+solve(i-1,k,sum-face))  %MOD;
        }

        return  dp[i][sum]=totalWays;
    }
    int numRollsToTarget(int n, int k, int target) {
       dp.assign(n+1,vector<int>(target+ 1,-1));

         return solve(n,k,target);
    }
};