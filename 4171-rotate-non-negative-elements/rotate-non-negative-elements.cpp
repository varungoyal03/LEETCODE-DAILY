class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>  values;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                values.push_back(nums[i]);
            }
        }
int m=values.size();

        if (m == 0) 
            return nums;

        k %= m;
int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
            
                //yaha par konsa aegga
                int index= (j+k)%m;
                nums[i]=values[index];
                j++;
            }
        }

        return nums;
    }

  
};