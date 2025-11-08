
class Solution {
    public:
   vector<vector<int>> t;
    int solveForAlice(bool AliceTurn,int i,vector<int>& piles){
        if(i==piles.size()) return 0;

           if(t[AliceTurn][i] != -1)
            return t[AliceTurn][i];

        int ub=min( i+3, (int) piles.size() );
        int stones=0;
        int ans=AliceTurn?INT_MIN:INT_MAX; //
        for(int j=i;j<ub;j++){
            stones+=piles[j];

              if(AliceTurn){
                ans=max(ans,stones +solveForAlice(false,j+1,piles));
                
              }
              else{
                ans=min(ans,solveForAlice(true,j+1,piles));
              }

        }
        return t[AliceTurn][i]=ans;
      
    }
    string stoneGameIII(vector<int>& piles) {
        int n=piles.size();
           t.assign(2, vector<int>(n+1, -1));
       int aliceScore= solveForAlice(true,0,piles);


        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        int bobScore = totalSum - aliceScore;

        if (aliceScore > bobScore) return "Alice";
        if (aliceScore < bobScore) return "Bob";
        return "Tie";
    }
};