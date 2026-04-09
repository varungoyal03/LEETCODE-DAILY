class Solution {
public:
double solvePow(double x, long long exp){
    if(exp==0) return 1.0;

    if(exp&1){//odd
       return x*solvePow(x*x,exp/2);
    }

    return solvePow(x*x,exp/2);

}
    double myPow(double x, int n) {
     long long exp=n;//imp

     if(exp<0){
       return solvePow(1.0/x,-exp);
     }   

     return solvePow(x,exp);
    }
};