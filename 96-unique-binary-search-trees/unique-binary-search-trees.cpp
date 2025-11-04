class Solution {
public:
vector<int> dp;
    int solve(int n){
        if(n==0) return 1;  // IMP
        if(n==1) return 1;
        if(n==2) return 2;
        

        if(dp[n]!=-1) return dp[n];

//i is centre (root nodes possible)  
int ans=0;
    for(int i=1;i<=n;i++){
           ans+= solve(i-1)*solve(n-i);
    }

    return dp[n]=ans;
     
    }
    int numTrees(int n) {
        
        dp.assign(n+1,-1);
        return solve(n);
    }
};

// bst ques left right and root split