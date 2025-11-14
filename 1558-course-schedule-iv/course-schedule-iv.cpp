class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //a->b

        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

          vector<unordered_set<int>> preReq(n); 

            // Topological sort
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);


            while(!q.empty()){

                int node=q.front(); q.pop();

                for(auto &v:adj[node]){
                         preReq[v].insert(node);

                         for(auto &x:preReq[node]){
                            preReq[v].insert(x);
                         }

                    if (--indegree[v] == 0)
                    q.push(v);
                }
            }


    vector<bool> ans;
        for (auto &q : queries)
            ans.push_back(preReq[q[1]].count(q[0]));

        return ans;
    }
};