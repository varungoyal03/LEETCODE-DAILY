class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;

        long long exp = n; // Protect against -2^31 overflow

        // Handle negative powers by inverting the base
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        double ans = 1.0;

        // If the exponent is odd, multiply the base into our answer
        while (exp > 0) {

            // IF ODD
          if (exp & 1) {
                ans = ans * x;
                exp = exp - 1; // Subtract 1 to make it even
            }
            // IF EVEN
            else {
                x = x * x;
               exp >>= 1; // Cut the power in half
            }
        }

        return ans;
    }
};