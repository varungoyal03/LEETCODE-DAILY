class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
                int n=nums.size();
        unordered_map<int,int> mp;
        int result=0;
        mp[nums[0]]=1;
        for(int i=1;i<n;i++){
            int curr=nums[i];

              mp[curr] = mp[curr-difference]+1;
              result=max(result,mp[curr]);
              }
  return result;  }
};