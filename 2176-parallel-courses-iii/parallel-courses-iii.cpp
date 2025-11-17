class Solution {
public:
vector<int> t;

    int  dfs(int i,vector<vector<int>>& adj, vector<int>& time){
    if(t[i]!=-1) return t[i];
        int maxTime=time[i-1];
        for(auto &v:adj[i]){
           maxTime=max(maxTime,time[i-1]+ dfs(v,adj,time));
        }

return t[i]=maxTime;

    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        t.assign(n+1,-1);

        for(auto &e:relations){
            adj[e[0]].push_back(e[1]);//      
        }
       

        for(int i=1;i<=n;i++){
            dfs(i,adj,time);
        }
return *max_element(t.begin(),t.end());

    }
};