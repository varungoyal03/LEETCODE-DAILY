#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        // 1. Handle edge cases (negatives are false, 0 is true)
        if (x < 0) return false;
        if (x == 0) return true; // Crucial: prevents log10(0) crash

        // 2. Find total digits and how many to reverse
        int digits = log10(x) + 1;
        int halfCount = digits / 2;
        int reversedHalf = 0;

        // 3. Reverse exactly the right half of the number
        while (halfCount--) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // 4. If total digits were odd, x still holds the middle digit. Chop it off.
        if (digits % 2 != 0) {
            x /= 10;
        }

        // 5. Compare the two halves
        return x == reversedHalf;
    }
};