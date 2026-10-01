class Solution {
public:

    int getMaxFreq(vector<int>& freq) {
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        return maxFreq;
    }

    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right] - 'A']++;

            // Get maximum frequency
            int maxFreq = getMaxFreq(freq);

            // Shrink window if replacements > k
            while ((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;

                // Recalculate max frequency
                maxFreq = getMaxFreq(freq);
            }

            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};