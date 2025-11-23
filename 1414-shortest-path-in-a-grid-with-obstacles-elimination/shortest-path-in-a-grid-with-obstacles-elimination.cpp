class Solution {
public:
typedef pair<int,int> PII;
  vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
          int m = grid.size();
        int n = grid[0].size();

          vector<vector<int>> visited(m, vector<int>(n, -1));

    if(0==m-1 && 0==n-1) return 0;
 queue<tuple<int,int,int>> q;//
        q.emplace(0,0,k);//i,j,k

        visited[0][0]=k;


        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [i,j,ElimationPower]=q.front(); q.pop();

                for(auto &[dx,dy]:directions){
                    int x=i+dx;
                    int y=j+dy;
                    int newPower=ElimationPower;

                    if(x<0 || y<0 || x>=m || y>=n) continue;

                    if(grid[x][y] && !newPower) continue;
                    if(grid[x][y]) newPower--;
                    if(visited[x][y] >= newPower ) continue;

                    if(x==m-1 && y==n-1) return level+1;

                    q.emplace(x,y,newPower);
                    visited[x][y]=newPower;             }
            }
            level++;
        }


        
  return -1;  }
};