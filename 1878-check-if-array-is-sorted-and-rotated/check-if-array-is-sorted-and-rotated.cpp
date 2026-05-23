class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

int minIndex=-1;
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]) {
                    minIndex=i;
                    break;
                }
            }

            if(minIndex==-1) return true;

            for(int i=0;i<n-1;i++){
                if(nums[minIndex%n]>nums[( minIndex+1 )%n]) return false;

                minIndex++;
            }

            return true;
    }
};