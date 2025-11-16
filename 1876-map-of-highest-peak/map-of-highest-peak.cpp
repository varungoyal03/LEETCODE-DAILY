class Solution {
public:
typedef pair<int,int> PII;
vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        

        

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<PII> q;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){ q.emplace(i,j);
                dist[i][j]=0;}
            }
        }

int level=0;

        while(!q.empty()){
          
            

            int size=q.size();
            while(size-- ){

                auto [r,c]=q.front(); q.pop();// 

                for(auto [dx,dy]:dirs){
                int x=r+dx; int y=c+dy;

                if(x<0 || y<0 || x>=m || y>=n ) continue;

                if(dist[x][y]> level+1 ) {
                    dist[x][y]=level+1;//
                    //visted cells will have distance less than level
                    q.emplace(x,y);
                }  }
         
         
         

            }
            level++;

        }




return dist;
    }
};





