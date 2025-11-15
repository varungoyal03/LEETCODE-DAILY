class Solution {
public:
typedef long long ll;
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
           vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){

             ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j=i+1;j<n;j++){
                
                
                ll x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];



                
                ll distance=1LL* (x2-x1)*(x2-x1) +1LL*(y2-y1)*(y2-y1);

                if(distance<=r1*r1){
                    adj[i].push_back(j);
                }
                if(distance<=r2*r2){
                    adj[j].push_back(i);
                }


            }
        }


int ans=0;

        // For each bomb, run BFS/DFS to count reachable bombs
              for (int start = 0; start < n; start++) {

                queue<int> q;
                 vector<bool> visited(n, false);

                q.push(start);
                visited[start]=1;
                int count=1;


                while(!q.empty()){
                    int u=q.front(); q.pop();
                    
                    for(int &v:adj[u]){
                        if(visited[v]) continue;

                        q.push(v);
                        visited[v]=1;
                        count++;
                    }

                }

  ans=max(ans,count);
              }
                


              





   return ans; }
};