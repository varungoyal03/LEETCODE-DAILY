class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

          if (n == 1) return {0};
          
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }

int count=0;

        while(!q.empty() ){
                int size=q.size();
                count+=size;

                if(count==n) break;//break when we are going to prcoess last queue

                while(size--){
                    int node=q.front(); q.pop();

                    for(auto v:adj[node]){
                        indegree[v]--;

                        if(indegree[v]==1) q.push(v);
                    }

                }
        }

     

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());  
        q.pop();                
    }

    return ans;}
};

//The "peeling" algorithm works because every leaf removal shrinks the diameter from both ends simultaneously — and the process stops exactly when we reach the center of that diameter.
// The height of a tree rooted at any node is the distance to its farthest node.

// The diameter (longest path) defines the maximum possible distance between any two nodes.

// No matter where you root the tree,
// the height can never be smaller than half the diameter,
// because the longest path must “reach” from one end toward the other.

// \U0001f449 The minimum possible height = ceil(diameter / 2).
// That’s achieved only when the root lies at the middle of the diameter —
// so that both sides are balanced.
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.