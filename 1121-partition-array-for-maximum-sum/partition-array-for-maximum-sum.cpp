class Solution {
public:

int solve(int i,vector<int>& nums, int k){
int n= nums.size();
    if(i==n) return 0;

    int sum=INT_MIN;
    int len=0;
int maxi=INT_MIN;

    for(int j=i;j<min(i+k,n);j++){
        maxi=max(maxi,nums[j]);
        len++;
        sum=max(sum,maxi*len +solve(j+1,nums,k));

    }

    return sum;
}
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n= nums.size();
    //    return  solve(0,nums,k);
       vector<int> dp(n+1,0);
    dp[n]=0;

       for(int i=n-1;i>=0;i--){

        int sum=INT_MIN;
        int len=0;
        int maxi=INT_MIN;

        for(int j=i;j<min(i+k,n);j++){
            maxi=max(maxi,nums[j]);
            len++;
            sum=max(sum,maxi*len +dp[j+1]);

        }

    dp[i]= sum;

       }

    return dp[0];}
};