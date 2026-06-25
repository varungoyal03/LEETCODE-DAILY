class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Sort the actual string directly using a custom rule
        auto lamda=[&](char a, char b) {
            
            // If they appear the same amount of times, use alphabetical order 
            // just to ensure identical characters stay grouped tightly together.
            if (freq[a] == freq[b]) {
                return a < b;
            }
            
            // Otherwise, sort strictly by whoever has the higher frequency count
            return freq[a] > freq[b];
        };
        sort(s.begin(), s.end(),lamda);

        return s;
    }
};