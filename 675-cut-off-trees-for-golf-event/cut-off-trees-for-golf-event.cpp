class Solution {
public:
int n,m;
typedef pair<int,int> PII;
vector<PII> directions={{1,0},{-1,0},{0,-1},{0,1}};

    int bfs(int sr,int sc,int x,int y,vector<vector<int>>& forest){
        if(x==sr && y==sc) return 0;

            queue<PII> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            q.push({sr,sc});
            visited[sr][sc]=1;

int level=0;
            while(!q.empty()){
                int size=q.size();//use varibel Size as N alresy there

                while(size--){
                    auto [r,c]=q.front(); q.pop();

                    for(auto [dx,dy]:directions){
                        int nr=r+dx;
                        int nc=c+dy;

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if(visited[nr][nc]) continue;

                        if(forest[nr][nc]==0) continue;
                        if(x==nr && y==nc) return level+1;

                        q.push({nr,nc});
                        visited[nr][nc]=1;

                    }


                }

                level++;
            }



          return -1;  
    }

    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();

        vector<vector<int>> trees; 
        // {height, row, col}

        // Collect all trees
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }

        // Sort trees by height (ascending)
        sort(trees.begin(), trees.end());

    int r=0,c=0;
    int steps=0;
        for(int i=0;i<trees.size();i++){
            int x=trees[i][1];
            int y=trees[i][2];
            int stepsNeeded= bfs(r,c,x,y,forest);
            if(stepsNeeded==-1) return -1;
            steps+=stepsNeeded;
     
            r=x;
            c=y;
            forest[r][c]=1;
            
                    }
    return steps;}
};