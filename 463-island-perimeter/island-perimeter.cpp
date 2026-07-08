

class Solution {
public:
    // 1. The Global Variable
    int perimeter = 0; 

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& grid) {
        
        if (grid[r][c] == -1) {
            return;
        }
        
        // Mark current cell as visited
        grid[r][c] = -1;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
             if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()|| grid[nr][nc] == 0 ){
                perimeter++;
                continue;
             }  
            
            dfs(nr, nc, grid);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        // MUST DO THIS: Reset the global variable for each new test case!
        perimeter = 0; 
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                
                if (grid[r][c] == 1) {
                    dfs(r, c, grid);
                    return perimeter; 
                }
                
            }
        }
        
        return 0;
    }
};