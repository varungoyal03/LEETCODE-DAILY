class Solution {
public:

int solve(int i,string &s, vector<vector<bool>> &pal ){
    if(i==s.size()) return 0;

 int miniCost=INT_MAX;

    for(int j=i;j<s.size();j++){
        if(!pal[i][i]) continue;

        miniCost=min(miniCost,1+solve(j+1,s,pal));

    }

    return miniCost;
}
    int minCut(string s) {
        int n=s.size();

        vector<vector<bool>> pal(n, vector<bool>(n,false));

        vector<int> dp(n+1, -1);

        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j] && (i-j<=2 || pal[j+1][i-1])){
                    pal[j][i] = true;
                }
            }
        }
     

        // solve(0,s,pal);
dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int  miniCost=INT_MAX;
            for(int j=i;j<n;j++){
            if(!pal[i][j]) continue;

            miniCost=min(miniCost,1+dp[j+1]);

    }

    dp[i]=miniCost;
        }
    
    return dp[0]-1;}
};