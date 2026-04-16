class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
//direct simulating 3*n we need to handle edge cases

        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        for(int i=0;i<n;i++) nums.push_back(nums[i]);

        set<pair<int,int>> s;
        for(int i=0;i<3*n;i++){
            s.insert({nums[i],i});
        }
        vector<int> ans;

        for(auto &q:queries){
          
                q+=n;//
                
            auto it=s.lower_bound({nums[q],q});
            int rightDist=next(it)->second-q;
            int leftDist=q-prev(it)->second;

           int result= min({leftDist,rightDist});
           ans.push_back(result==n?-1:result);
        }

        return ans;
    }
};