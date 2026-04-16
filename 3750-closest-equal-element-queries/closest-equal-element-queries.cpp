class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
//direcy simulating 3*n we need to handle edge cases
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            s.insert({nums[i],i});
            s.insert({nums[i],i+n});
            s.insert({nums[i],i+2*n});
        }
        vector<int> ans;

        for(auto &q:queries){
          int p=q+n;

            auto it=s.lower_bound({nums[q],p});//
            int rightDist=next(it)->second-p;
            int leftDist=p-prev(it)->second;

           int result= min({leftDist,rightDist});
           ans.push_back(result==n?-1:result);
        }

        return ans;
    }
};