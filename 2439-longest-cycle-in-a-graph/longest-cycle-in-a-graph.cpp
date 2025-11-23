class Solution {
public:
    int longestCycle(vector<int>& edges) {
          int n = edges.size();
        vector<int> indegree(n, 0);


            for(auto e:edges){
                if(e==-1 )continue;
                indegree[e]++;
            }



            
        queue<int> q;

       
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        //  BFS to remove all non-cycle nodes
        while (!q.empty()) {
            int u = q.front();  q.pop();

                int v = edges[u];
                if (v == -1) continue;
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);

            
        }

        int longest=-1;
      
      for(int i=0;i<n;i++){
        if(indegree[i]==0) continue; //alredyy proccesed

        int len=1;
     int j=edges[i];
        while(j!=i){
            indegree[j]=0;//proccesed
            j=edges[j];
            len++;
          
        }

longest=max(longest,len);



      }


   return longest; }
};