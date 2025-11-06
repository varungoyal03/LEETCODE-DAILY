class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
           int m=matrix.size();
        int n=matrix[0].size();
       //at every index from bottom  try to expand sQAURE down right diagonal
       vector<vector<int>> dp;
       dp.assign(m+1,vector<int>(n+1,0));
       int maxi=0;

       for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){

                if(matrix[i][j]=='0') continue;

            int down=dp[i+1][j];
            int diag=dp[i+1][j+1];
            int right=dp[i][j+1];

            dp[i][j]=1+min({down,diag,right});

            maxi=max(maxi,dp[i][j]);
        }}
        
    return maxi*maxi;}// return area
};



