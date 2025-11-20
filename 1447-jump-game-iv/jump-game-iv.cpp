class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;//

           unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)  mp[arr[i]].push_back(i);

        queue<int> q;
          vector<bool> visited(n,false);
        q.push(0);
        visited[0]=1;//

      
int level=0;

vector<int> next={-1,1};
        while(!q.empty()){
            int size=q.size();

            while(size--){
           int i= q.front(); q.pop();

           for(auto j:mp[arr[i]]) {

            if(visited[j]) continue;
            if(j==n-1) return level+1;

            q.push(j);
            visited[j]=1;


           }
        mp[arr[i]].clear();
                 // clear the list so we don't revisit same-value group

           for(auto dx:next){
           int  j=i+dx;

            if(j<0 || j>=n ) continue;//
            if( visited[j]) continue;
            if(j==n-1) return level+1;

            q.push(j);
            visited[j]=1;

           }

           


        }
        level++;
        }
        
    return -1;}
};