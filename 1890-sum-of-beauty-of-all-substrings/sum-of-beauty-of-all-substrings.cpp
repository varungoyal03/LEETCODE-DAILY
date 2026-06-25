class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();

        // The Anchor Loop: Where does our substring start?
        for (int i = 0; i < n; i++) {
            
            // Create a fresh inventory for this new anchor point
            int freq[26] = {0};

            // The Expanding Loop: Where does our substring end?
            for (int j = i; j < n; j++) {
                
                // 1. Update the tally in O(1) time
                freq[s[j] - 'a']++;

                // 2. Quickly find the max and min frequencies in O(26) time
                int maxFreq = 0;
                int minFreq = n; // Initialize to the maximum possible frequency (length of string)

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // 3. Add this substring's beauty to our grand total
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    
    }
};