class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;

        for(int bit : nums) {
            int newr = (  (x<<1)%5 + bit) % 5;
            ans.push_back(newr == 0);
            x=newr;
        }
        return ans;
    }  
    
};
