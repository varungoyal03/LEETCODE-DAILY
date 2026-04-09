class Solution {
public:
    vector<int> ans;
    int n,m;

    void solve(int d,vector<vector<int>>& matrix){
        int l=0+d;
        int r=n-1 -d;

        int t=0+d;
        int b=m-1-d;
        if(l>r || t>b) return ;

        for(int col=l;col<=r;col++) ans.push_back(matrix[t][col]);
        for(int row=t+1;row<=b-1;row++) ans.push_back(matrix[row][r]);
        if(t!=b) for(int col=r;col>=l;col--) ans.push_back(matrix[b][col]);
        if(l!=r) for(int row=b-1;row>=t+1;row--) ans.push_back(matrix[row][l]);

        solve(d+1,matrix);


    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         m=matrix.size();
         n=matrix[0].size();

        solve(0,matrix);

        return ans;
    }
};