class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int M = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m)); 

        long long prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                       ans[i][j] = prod;   
                prod = (prod * grid[i][j] ) % M; 
            }
        }
         prod = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
             ans[i][j] = (ans[i][j] * prod) % M;  
                prod = (prod * grid[i][j] ) % M; 
            }
        }




        return ans;
    }


};