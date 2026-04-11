class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.emplace_back(nums[i],i);
        }

        sort(v.begin(),v.end());

int ans=INT_MAX;
        for(int i=2;i<n;i++){
            if(v[i].first==v[i-2].first ){
                int val=v[i].second-v[i-2].second;

                ans=min(ans,2*val);
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};