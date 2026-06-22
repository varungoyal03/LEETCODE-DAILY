#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        // This will store the index of our "Anchor" element
        int ans = -1; 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // We haven't missed 'k' numbers yet. 
                // This is a safe anchor point! Save it.
                ans = mid;
                
                // Search right to find an even closer anchor
                low = mid + 1;
            } 
            else {
                // We missed too many numbers. Search left.
                high = mid - 1;
            }
        }

        // EDGE CASE: If ans is still -1, the missing number is before the array even starts.
        // Example: arr = [5, 6, 7], k = 2. The missing numbers are 1, 2, 3, 4. Answer is just 2.
        if (ans == -1) {
            return k;
        }

        // STEP 1: How many numbers were missing at our anchor point?
        int missing_at_anchor = arr[ans] - (ans + 1);
        
        // STEP 2: How many MORE numbers do we need to reach 'k'?
        int remaining_steps = k - missing_at_anchor;
        
        // STEP 3: Walk forward from the anchor!
        return arr[ans] + remaining_steps;
    }
};