class Solution {
public:
typedef pair<int,int> PII;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        
        queue<PII> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) q.emplace(i,j);
            }
        }
        int level=0;

if(q.empty() || q.size()==n*n ) return -1;//

        while(!q.empty()){
            int size=q.size();

            while(size--){
                  auto [i,j] =q.front(); q.pop();

                  for(auto [dx,dy]:dirs){
                   int  x=i+dx;
                   int  y=j+dy;

                    if(x<0 || y<0 || x>=n || y>=n) continue;
                    if( grid[x][y]==1) continue;

                    q.emplace(x,y);//
                    grid[x][y]=1;//
                   
                  }
            }

            level++;
            cout<<level;
        }
   
   return level-1; }
};