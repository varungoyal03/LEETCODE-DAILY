
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Track the minimum obstacles removed to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Deque stores: {obstacles_removed, {row, col}}
        deque<pair<int, pair<int, int>>> dq;
        
        // Direction vectors for Up, Down, Left, Right
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        // Start at the top-left corner
        // (If the start is an obstacle, it costs 1 to enter it. If 0, it costs 0.)
        dist[0][0] = grid[0][0];
        dq.push_front({dist[0][0], {0, 0}});
        
        while (!dq.empty()) {
            
            // Extract using C++17 structured bindings
            auto [currDist, coords] = dq.front();
            auto [x, y] = coords;
            dq.pop_front();
            
            // ==========================================
            // YOUR OPTIMIZATION: The "Stale State" Check
            // ==========================================
            if (currDist > dist[x][y]) {
                continue;
            }
            
            // BASE CASE: We reached the bottom-right corner!
            if (x == m - 1 && y == n - 1) {
                return currDist;
            }
            
            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Boundary check
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    
                    // The cost to move into the next cell is literally its grid value
                    int costToEnter = grid[nx][ny];
                    int newDist = currDist + costToEnter;
                    
                    // If we found a path that breaks fewer walls, update it!
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        
                        // THE 0-1 BFS MAGIC:
                        // Free path? Push Front. Paid path? Push Back.
                        if (costToEnter == 0) {
                            dq.push_front({newDist, {nx, ny}});
                        } else {
                            dq.push_back({newDist, {nx, ny}});
                        }
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1];
    }
};