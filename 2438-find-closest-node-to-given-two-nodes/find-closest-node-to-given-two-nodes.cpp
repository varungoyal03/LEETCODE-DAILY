class Solution {
public:
// Iterative only. As there's only 1 outgoing edge, we can traverse the graph from node to node in a simple loop


    void dfs(int start, const vector<int>& edges, vector<int>& dist){
        int d=0;

    dist[start]=0;//IMP
        int curr=edges[start];
        

        while(1){
            if(curr==-1 || dist[curr]>=0)  break;//

            ++d;
            dist[curr]=d;
            curr=edges[curr];
  
        }


    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        if(node1==node2) return node1;//

          vector<int> dist1(n, -1), dist2(n, -1);
          dfs(node1,edges, dist1);
          dfs(node2,edges, dist2);

int ans=-1;
int best=INT_MAX;
        for(int i=0;i<n;i++){
           if(dist1[i]==-1 || dist2[i]==-1) continue; 

            int d=max(dist1[i],dist2[i]);
            if(d<best){//make d minimum
                best=d;
                ans=i;
              
            }
        }


return ans;

    }
};