class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
//nums is sorted
vector<int> color(n);
int grp=0;
color[0]=grp;

        for(int i=1;i<n;i++){
           if (abs( nums[i-1]-nums[i])<=maxDiff){
            color[i]=grp;
           }
           else{
            grp++;
             color[i]=grp;
           }
        }


vector<bool> ans;
        for(auto &q:queries){
            if(color[q[0]]==color[q[1]]) ans.push_back(true);

            else ans.push_back(false);

        }

        return ans;
    }
};

