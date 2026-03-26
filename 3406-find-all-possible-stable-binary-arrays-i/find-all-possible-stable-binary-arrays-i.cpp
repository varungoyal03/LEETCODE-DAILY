class Solution {
public:
    int M = 1e9 + 7; 
    int dp[202][202][2];    
    int solve(int one, int zero, bool ms, int limit){
        if(one==0 && zero==0) return 1;
        
        int ans = 0;

        if(dp[one][zero][ms]!=-1){
            return dp[one][zero][ms];
        }
        
        if(ms==true)//prev i have taken 0 
        {
            for(int i=1; i<=min(one,limit); i++){
                ans = (ans+solve(one-i,zero,false,limit)%M)%M ;
            }
        }
        else {//prev i have taken 1
            for(int i=1; i<=min(zero,limit); i++){
                ans = (ans+solve(one,zero-i,true,limit)%M)%M ;
            }
        }
        return dp[one][zero][ms] = ans%M; 
    }
    int numberOfStableArrays(int zero, int one, int limit) {
         memset(dp,-1,sizeof(dp)) ;
         int a=solve(one,zero,true,limit)%M;
         int b= solve(one,zero,false,limit)%M;
         return (a+b)%M;    
    }
};