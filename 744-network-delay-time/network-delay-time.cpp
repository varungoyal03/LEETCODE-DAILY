class Solution {
public:
using p=pair<int,int>;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<p>> adj(n+1);
        for(auto &e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;

        vector<int> dist(n+1,1e9);
        
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){

            auto [currDist,node]=pq.top();
            pq.pop();

            if(currDist>dist[node]) continue;

            for(auto &[nei,wt]:adj[node]){
                if(currDist+wt< dist[nei] ){
                    dist[nei]=currDist+wt;
                    pq.push({dist[nei],nei});
                }
            }
        }

        //  Find the maximum time it took to reach any node
        int max_time = 0;
        // Start at 1 because nodes are 1-indexed
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1; // A node was completely unreachable
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;        
    }
};