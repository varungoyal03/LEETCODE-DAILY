

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // UPGRADE: deque now holds {current_distance, {x, y}}
        deque<pair<int, pair<int, int>>> dq;
        
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        
        // Push distance 0, and coordinates {0, 0}
        dq.push_front({0, {0, 0}});
        dist[0][0] = 0;

        while (!dq.empty()) {
            
            // EXTRACT: Unpacking a nested pair using C++17 structured bindings
            auto [currDist, coords] = dq.front();
            auto [x, y] = coords; 
            dq.pop_front();
            
            // THE OPTIMIZATION: Stale State Check
            if (currDist > dist[x][y]) {
                continue;
            }

            int curDir = grid[x][y] - 1;

            if (x == m - 1 && y == n - 1) {
                return dist[x][y]; // Or return currDist, both are exactly the same here!
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int cost = dist[x][y] + (dir == curDir ? 0 : 1);
                
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    
                    // PUSH: Notice the nested curly braces {{nx, ny}}
                    if (dir == curDir) dq.push_front({cost, {nx, ny}});
                    else dq.push_back({cost, {nx, ny}});
                }
            }
        }

        return 0;
    }
};