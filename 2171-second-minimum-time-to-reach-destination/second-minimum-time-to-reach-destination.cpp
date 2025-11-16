class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> adj(n+1);
            for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector< vector<int> > dist(n+1);
        queue<pair<int,int>> q;
        q.push({1, 0}); // (node, edgeCount)

int count=-1;

        while(!q.empty()){
            auto [u, d] = q.front(); q.pop();
            if(u==n){
                if(count==-1) count=d;
                else {
                    count=d;
                    break;
                }
            }
            for (int &v : adj[u]) {
                if(dist[v].size()==2)  continue;
                if(dist[v].size()==1 and dist[v][0]== d+1) continue;

                q.emplace(v,d+1);
                dist[v].push_back(d+1);

        }
        }



        auto edgesToTime = [&](int edgeCount) {
            int t = 0;
            for (int step = 0; step < edgeCount; step++) {
                if ((t / change)  & 1 ) { // red light
                    t = (t / change + 1) * change;
                }
                t += time;
            }
            return t;
        };
cout<<count;
        return edgesToTime(count);


    }
};