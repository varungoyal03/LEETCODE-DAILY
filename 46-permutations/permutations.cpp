class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> visited;
    void DFS(vector<int>& nums){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i] = true;
                DFS(nums);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visited.assign(n, false);
        DFS(nums);
        return res;
    }
};