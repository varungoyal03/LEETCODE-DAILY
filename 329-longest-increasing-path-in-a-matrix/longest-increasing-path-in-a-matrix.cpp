class Solution {
public:
int m,n;
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
int t[201][201];

int  dfs(int r,int c ,vector<vector<int>>& matrix){
if (t[r][c] != -1) return t[r][c];

    int len=1;
    for(auto &[dx,dy]:dir){
        int x=r+dx;
        int y=c+dy;

        if(x<0|| y<0 || x>=m|| y>=n || matrix[x][y]<=matrix[r][c]) continue;

        len=max(len,1+dfs(x,y,matrix));

    }
    return t[r][c]=len;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
         n=matrix[0].size();
         memset(t,-1,sizeof(t));

        int ans = 0;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                ans = max(ans, dfs(r, c,matrix));
        return ans;
    }
};