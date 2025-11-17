class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        
        multiset<int> s;

        int ans=0;
        int l=0;

        for(int r=0;r<n;r++){
            s.insert(nums[r]);
            while(*s.rbegin()-*s.begin() > limit){
                s.erase( s.find(nums[l]) );
                l++;
            }
            ans=max(ans,r-l+1);
        }
    
    return ans;}
};
