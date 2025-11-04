class Solution {
public:

int t[101][101];

int solve(int row,int col,vector<vector<int>>& matrix){
      int n=matrix.size();
        if(row==n-1 ) return t[row][col]= matrix[row][col];

int mini=1e9;
        if(t[row][col] != -1)
            return t[row][col];

        for(int shift=-1;shift<=1;shift++){
        if(col+shift>=0  && col+shift< n)
           mini=min(mini,solve(row+1 ,col+shift,matrix));
        }

        return t[row][col]=matrix[row][col]+mini;

}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        memset(t, -1, sizeof(t));  //
        int ans=INT_MAX;

        for(int row=n-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                  if(row==n-1 ) { t[row][col]= matrix[row][col]; continue;}
                    

                int mini=1e9;              
                    for(int shift=-1;shift<=1;shift++){
                    if(col+shift>=0  && col+shift< n)
                    mini=min(mini,t[row+1 ][col+shift]);
                    }

                    t[row][col]=matrix[row][col]+mini;



             }
        }



        // for(int col=0;col<n;col++){

        //     // ans=min(ans,solve(0,col,matrix));


        // }


         for(int col=0;col<n;col++){

              ans=min(ans,t[0][col]);


         }



        return ans;
    }
};