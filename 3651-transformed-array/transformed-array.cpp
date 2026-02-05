class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> result(n);

        for(int i=0;i<n;i++){
            if(nums[i]==0)  result[i]=nums[i];

            else if(nums[i]>0) {

                int steps=nums[i];
                result[i]= nums[(i+steps)%n];

            }
            else{
                int steps=-nums[i];
                int index=(i-steps)%n;
                result[i]= nums[ (index +n )%n];
            }
        }
    return result;    
    }
};