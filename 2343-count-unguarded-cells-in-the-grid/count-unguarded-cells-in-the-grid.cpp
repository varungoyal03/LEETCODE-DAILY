class Solution {
public:
    const int EMPTY = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markGuard(vector<int>& gaurd, vector<vector<int>>& grid, int m,
                   int n) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int r = gaurd[0], c = gaurd[1];
        for (auto& d : dirs) {

            int x = r + d[0], y = c + d[1];
            while (x >= 0 && y >= 0 && x < m && y < n) {

                if (grid[x][y] == EMPTY || grid[x][y] == GUARDED)
                    grid[x][y] = GUARDED;
                else
                    break;

                x += d[0];
                y += d[1];
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, EMPTY));

        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        for (auto& guard : guards) {
            markGuard(guard, grid, m, n);
        }

        int count = 0;
        for (auto& row : grid) {
            for (auto& cell : row) {
                if (cell == EMPTY)
                    count++;
            }
        }
        return count;
    }
};
// multisource dfs
