class Solution {
public:
    void bfs(int src, int idx, vector<vector<int>>& adj, vector<vector<int>>& dist) {
        queue<int> q;
        q.push(src);
        dist[src][idx] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v][idx] == -1) {
                    dist[v][idx] = dist[u][idx] + 1;
                    q.push(v);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist(n, vector<int>(3, -1));

        bfs(x, 0, adj, dist);
        bfs(y, 1, adj, dist);
        bfs(z, 2, adj, dist);

        int ans = 0;
        for (auto& d : dist) {
            sort(d.begin(), d.end());
            long long a = d[0], b = d[1], c = d[2];
            if (a*a + b*b == c*c) ans++;
        }
        return ans;
    }
};
