class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i=1;i<n;i++){
            int prev=nums[i-1];
            int curr=nums[i];

            for(int i=prev+1;i<curr;i++){
                ans.push_back(i);
            }

        }
  return ans;  }
};