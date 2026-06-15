class Solution {
public:
    const int MOD = 1e9 + 7;
        int t[102][102][102];

    int solve(int i,int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(i==group.size()){
            return   t[i][n][minProfit]= minProfit==0;
        } 
        
        if(  t[i][n][minProfit]!=-1 ) return   t[i][n][minProfit];
        long long notTake=solve(i+1,n,minProfit,group,profit);
        long long take=0;
        if(  n-group[i]>=0 ){
            int newProfit=max(minProfit-profit[i] ,0); 
            take=solve(i+1,n-group[i], newProfit,group,profit);}

  return   t[i][n][minProfit]= (take+notTake)%MOD;//
    }

  
    int profitableSchemes(int N, int minprofit, vector<int>& group, vector<int>& profit) {
        // ALL POSSIIIBEL SUBSET EXPOLE==> TAKE IT OR NOT TAKE
 memset(t,-1,sizeof(t));
       return  solve(0,N,minprofit,group,profit);




   
    
}

};