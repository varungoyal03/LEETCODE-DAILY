class Solution {
public:
// we want to find ONLY friends at the given level
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
int n=watchedVideos.size();

queue<int> q;
vector<bool> visited(n,false);

q.push(id);
visited[id]=true;


int currLevel=0;
while(!q.empty()){

    int size=q.size();
    while(size--){
        int node=q.front(); q.pop();

        for(auto &fr:friends[node]){
            
            if(visited[fr]) continue;
            q.push(fr);
            visited[fr]=true;
        }
    }
    currLevel++;
    if(currLevel==level) break;
}

    unordered_map<string,int> mp;
    while(!q.empty()){
        int node=q.front(); q.pop();
        for(auto video:watchedVideos[node]){
            mp[video]++;
        }  
    }

vector<pair<int,string> > ans;
    for(auto &p:mp){
        ans.emplace_back(p.second,p.first);//{freq,video}
    }

sort(ans.begin(),ans.end());


        vector<string> result;
        for (auto &p :ans) result.push_back(p.second);
        return result;
        
    }
};