class Solution {
public:
int MOD=1e9 +7;
long long solvePow(long long x, long long exp){
    if(exp==0) return 1.0;

    x%=MOD;//IMP
    if(exp&1){//odd
       return (x*solvePow(x*x,exp/2))% MOD;
    }

    return solvePow(x*x,exp/2)% MOD;;

}

    int countGoodNumbers(long long n) {
 long long evenCount = (n + 1) / 2; // ceil
        long long oddCount = n / 2;        // floor

        long long evenWays = solvePow(5, evenCount);
        long long oddWays = solvePow(4, oddCount);

        return (evenWays * oddWays) % MOD;
        
    }
};
