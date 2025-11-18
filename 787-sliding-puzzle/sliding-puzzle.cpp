class Solution {
public:
typedef pair<string,int>  PSI;
    int slidingPuzzle(vector<vector<int>>& board) {
         vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";

   string start="";
          for (auto &row : board) {
            for (auto &col : row) {
                start += col + '0';
                
            }
        }

        if(start==target) return 0;

        int pos0=start.find('0');


        queue<PSI>  q;
        set<string> visited;

        q.emplace(start,pos0);
        visited.insert(start);

int level=0;
        while(!q.empty()){//
            int size=q.size();
         
            while(size--){
               auto [state,i]= q.front(); q.pop();

               for(int v:adj[i]){
                string newState=state;
               
                swap(newState[i],newState[v]);
              
              if( visited.count(newState) ) continue;
               if(newState==target) return level+1;

                q.emplace(newState,v);
               visited.insert(newState);
               }


            }
            level++;

        }






return -1;
    }
};


