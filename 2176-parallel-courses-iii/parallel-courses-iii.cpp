class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n+1];
        vector<int> id(n+1, 0);

        // Build adjacency list and indegree
        for (auto &i : relations) {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            id[b]++;
        }

        queue<int> q;
        vector<int> finish(n+1, 0); // stores minimum finish time for each course

        // ✅ Fix 1: Start loop from 1 to n (not 0)
        for (int i = 1; i <= n; i++) {
            if (id[i] == 0) {
                q.push(i);
                finish[i] = time[i - 1];  // di rectly set its completion time
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            // ✅ Fix 2: Use adj[temp], not adj[i]
            for (auto j : adj[temp]) {
                // update finish time for dependent course
                finish[j] = max(finish[j], finish[temp] + time[j - 1]);

                id[j]--;
                if (id[j] == 0) {
                    q.push(j);
                }
            }

            ans = max(ans, finish[temp]); // keep track of max finish time
        }

        return ans;
    }
};