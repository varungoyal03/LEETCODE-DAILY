class Solution {
public:

    long long maxSumTrionic(vector<int>& nums) {
       int  n = nums.size();


    const long long NEG = LLONG_MIN / 2;

    vector<vector<long long>> dp(n + 1, vector<long long>(4, NEG));

    // base case
    // dp[n-1][3] = max(nums[n-1],0);wrong

    dp[n-1][3]=nums[n-1];
    // dp[n-1][0]= dp[n-1][1]=dp[n-1][2]=NEG;



    for(int i = n - 2; i >= 0; i--) {
            int curr = nums[i];


    
        int next = nums[i+1];

        

        //0
        dp[i][0]=dp[i+1][0];//skip
        if(next>curr) dp[i][0]=max(dp[i][0],curr+dp[i+1][1]);


        //1
        if(next>curr) dp[i][1]=curr+dp[i+1][1];
        if (next<curr) dp[i][1]=curr+dp[i+1][2];


        //2
        if(next<curr) dp[i][2]=curr+dp[i+1][2];
        if (next>curr) dp[i][2]=curr+ dp[i+1][3];

        //3
        dp[i][3]=curr;//stop
        if(next>curr) dp[i][3]=max(dp[i][3],curr+dp[i+1][3]);

    }

    return dp[0][0];}
};

