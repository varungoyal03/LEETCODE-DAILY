class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return 0;
        map<int,int> mp;
        for(auto &x:nums) mp[x]++;

        int grps=n/k;

        for(auto &[x,f]:mp){
            if(f>grps) return false;
        }

        return true;
     
    }
};

