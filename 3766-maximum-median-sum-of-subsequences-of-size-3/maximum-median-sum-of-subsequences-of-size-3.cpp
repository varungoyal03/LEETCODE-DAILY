class Solution {
public:
using ll=long long;
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
         ll sum=0;
         sort(nums.begin(),nums.end());
         int j=n-2;
         for(int i=0;i<n/3;i++){
            sum+=nums[j];
        j-=2;
         }
   return sum; }
};
