class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
int a=1e8,b=1e8;

        for(int i=1;i<n;i++){
            if(nums[i]<a){
                b=a;
                a=nums[i];

            }
            else if(nums[i]<b){
                b=nums[i];
            }
        }

        return nums[0]+a+b;

    }
};