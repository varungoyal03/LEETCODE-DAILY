class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
int count=0;
        for(auto &x:nums){
           count+= maxi-x;
        }
   return count; }
};