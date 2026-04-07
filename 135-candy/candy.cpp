class Solution {
public:
    int candy(vector<int>& ratings) {
        //no contraint at equalt ratings

      int n = ratings.size();
        vector<int> adj[n];
        vector<int> deg(n, 0);
        vector<int> dist(n, 1);//candies

        for (int i = 0; i < n; i++) {
            // Check left neighbor
            if (i > 0 && ratings[i] > ratings[i-1]) {
                adj[i-1].push_back(i);
                deg[i]++;
            }
            // Check right neighbor
            if (i < n - 1 && ratings[i] > ratings[i+1]) {
                adj[i+1].push_back(i);
                deg[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        int total=0;
        while(!q.empty()){
            int top=q.front(); q.pop();
            total+=dist[top];

            for(auto v:adj[top]){
                dist[v]=max(dist[v],dist[top]+1);
                deg[v]--;
                  if (deg[v] == 0) q.push(v);


            }
        }
        


    return total;

    }
};

