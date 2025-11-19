class Solution {
public:
int m;
int n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
         int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;


            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                      if(land[i][j] ==  0 ) continue;

                      int r2=i; int c2=j;

                    // extend downward
                    while(r2 < m && land[r2][j] == 1)
                        r2++;

                    // extend rightward
                    while(c2 < n && land[i][c2] == 1)
                        c2++;


                    ans.push_back({i, j, r2 - 1, c2 - 1});

                    // mark rectangle visited
                    for(int r = i; r < r2; r++)
                        for(int c = j; c < c2; c++)
                            land[r][c] = 0;   



                }
            }

            return ans;
    }
};