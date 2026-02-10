class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = -1;
       vector<int> dp(m,1);//dp[i] is logest string ending at col i;
       
       for(int col=0;col<m;col++){
        for(int prevCol=col-1 ;prevCol>=0;prevCol--){

            int canPick=true;
            for(int row=0;row<n;row++){
                if ( strs[row][prevCol] > strs[row][col]) {
                    canPick = false;
                    break;
                }
            }

          if(canPick) {
            dp[col]=max(dp[prevCol]+1,dp[col] );
          }  

        }
    ans=max(ans,dp[col]);

       }

   return m-ans; }
};



// col pick/not pick