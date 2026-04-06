class Solution {
public:
        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> blocked;
        for(auto &v:obstacles) blocked.insert({v[0],v[1]});
        
        int x = 0, y = 0;
        int dir = 0; // start facing North
        int maxDist = 0;

        for(auto cmd:commands){
            if(cmd==-2) dir=(dir-1+4)%4;
            else if(cmd==-1) dir=(dir+1)%4;

            else{

                    while(cmd--){
                        int nx=x+directions[dir].first;
                        int ny=y+directions[dir].second;

                        if(blocked.count({nx,ny})) break;

                        x=nx;
                        y=ny;
                        maxDist=max(maxDist,x*x+y*y);

 
                    }


            }
        }
        

   return maxDist; }
};

