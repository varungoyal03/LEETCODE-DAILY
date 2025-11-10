class Solution {
public:
 vector<vector<int>> adj;
   vector<vector<int>> dp; // dp[u][power] memo table
 int solve(int u,int power,int parent,vector<int>& coins, int k){
    if(power>=14) return 0;
      if (dp[u][power] != -1)
            return dp[u][power];

        int choice1=(coins[u]>>power) -k ;
        int choice2=coins[u]>>(power+1);



        for(auto &v:adj[u]){
            if(v==parent)  continue;
                choice1+=solve(v,power,u,coins,k);
                choice2+=solve(v,power+1,u,coins,k);
        }

        return dp[u][power]=max(choice1,choice2);

 }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {

        int n=edges.size()+1;//


       adj.assign(n,{});//
         dp.assign(n, vector<int>(15, -1));

       for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       return solve(0,0,-1,coins,k);


    }
};