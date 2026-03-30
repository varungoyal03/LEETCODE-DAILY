class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int num1=-1e9;
        int num2=-1e9;
        int ans=1e9;

        int n=nums.size();
        for(int i=0;i<n;i++){

            if(nums[i]==1) { ans=min(ans,i-num2); num1=i;}
            else if(nums[i]==2) { ans=min(ans,i-num1); num2=i; }
        }


return ans==1e9?-1:ans;
    }
};