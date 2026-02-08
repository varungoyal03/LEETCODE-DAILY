class Solution {
    using ll=long long;
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        ll ans=-1e17;

        if(m==1)  {
            for (auto it : nums) {
                ll v = 1LL * it * it;
                ans = max(ans, v);
            }
            return ans;
        }

        ll maxPrefix=-1e17;
        ll minPrefix=1e18;
int j=0;
        for(int i=m-1;i<n;i++){
         
                maxPrefix=max(maxPrefix,1LL* nums[j]);
                minPrefix=min(minPrefix,1LL* nums[j]);
                j++;

            ans=max({ans,
            maxPrefix*nums[i],
            minPrefix*nums[i]});

            

       

        }
        return ans;
    }
};