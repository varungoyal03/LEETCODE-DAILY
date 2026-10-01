class Solution {
public:
    string reverseWords(string s) {

        // Remove extra spaces
        int n = s.size();
        int i = 0, j = 0;

        while (i < n) {

            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            if (j > 0)
                s[j++] = ' ';

            while (i < n && s[i] != ' ')
                s[j++] = s[i++];
        }

        s.resize(j);

        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};