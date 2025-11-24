class Solution {
public:
    vector<vector<int>> t;
    int n;

    int solve(int i,int r,vector<int>& nums){
            if(i==n) {
                if(r==0) return 0;
                else return INT_MIN;
            };
        
            if(t[i][r]!=-1) return t[i][r];

          int notTake=solve(i+1,r,nums);

          int newr= (r+nums[i])%3;


          int take=nums[i]+solve(i+1,newr,nums);
         return t[i][r]=max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        t.assign(n, vector<int>(3, -1));
        return solve(0, 0,nums);
    }
};