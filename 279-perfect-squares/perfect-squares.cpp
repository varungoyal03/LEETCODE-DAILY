class Solution {
public:
vector<int> t;
    int solve(int n){
        if(n==0 ) return 0;
        if(t[n]!=-1) return t[n];

            int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
           ans=min(ans,1+ solve(n-i*i));
        }

        return t[n]=ans;
    }


    int numSquares(int n) {
        t.assign(n+1,-1);


        // return solve(n);

        t[0]=0;

        for(int i=1;i<=n;i++){
            
            int ans=INT_MAX;
        for(int j=1;j*j<=i;j++){//
           ans=min(ans,1+ t[i-j*j] );//
        }

         t[i]=ans;
        }
   return t[n]; }
};