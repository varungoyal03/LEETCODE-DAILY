class Solution {
    using ll=long long ;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //(r)-(l-1)

        int n=nums.size();

        vector<ll> dp(k,1e18);

    
        dp[k-1]=0;

      
        
        ll prefix_sum=0;
        ll ans=-1e17;
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
        if(dp[i%k]!=1e18) {   ll ans1=prefix_sum-dp[i%k];
         ans=max(ans,ans1);}       
      

dp[i%k]=min(dp[i%k],prefix_sum);


            }
   return ans; }
};