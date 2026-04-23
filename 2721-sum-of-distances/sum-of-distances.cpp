class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        
        vector<long long> ans(n, 0);

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &it : mp){
            auto &pos = it.second;
            
            long long totalSum = 0;
            for(int x : pos) totalSum += x;

            long long leftSum = 0;
            int m = pos.size();
            if(m==1) continue;

            for(int i=0;i<m;i++){
                  long long rightSum = totalSum - leftSum - pos[i];

                 long long left  = 1LL* i*pos[i] -leftSum;
                 long long right=rightSum- 1LL* (m-i-1)*pos[i];


                ans[pos[i]] = left + right;


                  leftSum += pos[i];
            }
            
            }
        


return ans;

    }
};