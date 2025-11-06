class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       //at every index try to expand sQAURE UP AND LEDFT
       vector<vector<int>> dp;
       dp.assign(m+1,vector<int>(n+1,0));
       int sum=0;

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

                if(matrix[i][j]==0) continue;

            int up=i?dp[i-1][j]:0;
            int diag=i && j ?dp[i-1][j-1]:0;

            int left=j?dp[i][j-1]:0;

            dp[i][j]=1+min({up,diag,left});
            sum+=dp[i][j];
        }


       } 


     
   return sum; }
};