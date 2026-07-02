class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // Base case: if array is empty, 0 candies needed
        if (n == 0) return 0;
        
        // The first child gets 1 candy to start
        int sum = 1; 
        int i = 1;
        
        // Traverse the entire array
        while (i < n) {
            
            // 1. Handle flat terrain (equal ratings)
            if (ratings[i] == ratings[i - 1]) {
                sum = sum + 1; 
                i++; 
                continue;
            }
            
            // 2. Handle going UP the mountain
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1; 
                sum += peak; 
                i++;
            }
            
            // 3. Handle going DOWN the mountain
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down; 
                i++; 
                down++;
            }
            
            // 4. Fix the collision at the peak
            // If the downward slope is longer than the upward slope, 
            // the peak needs extra candies to satisfy the downward rule.
            if (down > peak) {
                sum += down - peak;
            }
        }
        
        return sum;
    }
};