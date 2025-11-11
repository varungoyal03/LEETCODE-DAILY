class Solution {
public:
    int  MOD=1e9 +7;
    int t[101][201];
    int solve(int start, int finish, int fuel,vector<int>& locations){
        
        if(t[start][fuel]!=-1 ) return t[start][fuel];
            int ans=0;
            if(start==finish) ans+=1;
          
            for(int j=0;j<locations.size();j++){
                if(j==start) continue;
                  int fuelNeed=abs( locations[start]-locations[j]);
                  if(fuel<fuelNeed) continue;

               ans=(ans+ solve(j,finish,fuel-fuelNeed,locations))% MOD;

            }
            return t[start][fuel]= ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(t,-1,sizeof(t));
       return  solve(start,finish,fuel,locations);
    }
};