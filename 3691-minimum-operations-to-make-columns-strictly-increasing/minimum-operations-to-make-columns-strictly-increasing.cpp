class Solution {
public:
int minimumOperations(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();;
    int ans = 0;
    for(int c = 0; c < n; ++c){
        for(int r = 1; r < m ;++r){
            if(grid[r][c] > grid[r-1][c]) continue;
            
            ans += grid[r-1][c] + 1 - grid[r][c];
            grid[r][c] = grid[r-1][c] + 1;
        }
    }
    return ans;
}
};