class Solution {
public:

    //  vector<vector<int>> serves={{100, 0}, {75, 25}, {50, 50}, {25, 75}};
 vector<vector<int>> serves={{4, 0}, {3, 1}, {2, 2}, {1, 3}};
    vector<vector<double>> t;
     double solve(int A,int B){
         if(A <= 0 && B <= 0)
            return 0.5;
        
        if(A <= 0)
            return 1.0;
        if(B <= 0)
            return 0.0;

        if(t[A][B] != -1.0)
            return t[A][B];


            double totalProb=0;
        for(auto &serve:serves){
               totalProb+=0.25*solve(A-serve[0],B-serve[1]);
        }

    return t[A][B]=totalProb;
     }
    double soupServings(int n) {
        if(n>=5000) return 1;

 n = (n + 24) / 25;  // integer-only safe version   

        t.resize(n+1,vector<double> (n+1,-1.0));
        return solve(n,n);
    }
};