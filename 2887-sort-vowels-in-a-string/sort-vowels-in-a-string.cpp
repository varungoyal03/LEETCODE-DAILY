class Solution {
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        vector<int> count(256, 0);
        
        // Count every vowel in the string
        for (char c : s) {
            if (isVowel(c)) {
                count[c]++;
            }
        }
        
        // The perfectly sorted order of vowels based on ASCII values
        string sortedVowels = "AEIOUaeiou";
        int vowel_idx = 0; // Pointer to iterate through our 10 buckets
        
        // Step 2: Replace vowels in the original string
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                
                // Skip empty buckets until we find a vowel we actually have
                while (count[sortedVowels[vowel_idx]] == 0) {
                    vowel_idx++;
                }
                
                // Place the vowel and remove one token from its bucket
                s[i] = sortedVowels[vowel_idx];
                count[sortedVowels[vowel_idx]]--;
            }
        }
        
        return s;
    }
};