class Solution {
public:

 int t[2][101][101]; //t
    int solveForAlice(bool AliceTurn,int i,int M,vector<int>& piles){
        if(i==piles.size()) return 0;

           if(t[AliceTurn][i][M] != -1)
            return t[AliceTurn][i][M];

        int ub=min( i+2*M, (int) piles.size() );
        int stones=0;
        int ans=AliceTurn?0:INT_MAX;
        for(int j=i;j<ub;j++){
            stones+=piles[j];

              if(AliceTurn){
                ans=max(ans,stones +solveForAlice(false,j+1,max(M,j-i+1),piles));
                
              }
              else{
                ans=min(ans,solveForAlice(true,j+1,max(M,j-i+1),piles));
              }

        }
        return t[AliceTurn][i][M]=ans;
      
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
       return solveForAlice(true,0,1,piles);
    }
};