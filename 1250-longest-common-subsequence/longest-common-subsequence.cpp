class Solution {
public:
    int find(int i,int j,string &s1, string &s2,     vector<vector<int>> &dp){
        if(i<0 || j<0 ) return 0;
if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return 1+find(i-1,j-1,s1,s2,dp);

        return dp[i][j]=max(find(i,j-1,s1,s2,dp),find(i-1,j,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int >(m,-1));
        return find(n-1,m-1,s1,s2,dp);
    }
};