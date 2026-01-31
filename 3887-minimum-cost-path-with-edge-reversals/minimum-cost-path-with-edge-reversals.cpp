class Solution {
public:
using ll=long long ;
    int minCost(int n, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> adj(n);

    for (auto &edge:edges) {
        int u=edge[0], v=edge[1], w=edge[2];
        
        // 0-indexed, for 1-indexed input: --u, --v
        adj[u].push_back({v, w});
        adj[v].push_back({u,2*w}); // remove if directed
    }

      vector<ll> dist(n, 1e18);
int src=0;
    dist[src] = 0;

    // min-heap {distance, node}
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue; // stale entry

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return (dist[n-1] == 1e18 ? -1:dist[n-1]);
    }
};