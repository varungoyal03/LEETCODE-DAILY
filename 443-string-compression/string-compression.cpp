class Solution {
public:
    int compress(vector<char>& chars) {

        int read = 0;
        int write = 0;

        while (read < chars.size()) {

            // Current character
            char ch = chars[read];

            // Find how many times it repeats
            int count = 0;

            while (read < chars.size() && chars[read] == ch) {
                count++;
                read++;
            }

            // Write the character
            chars[write++] = ch;

            // Write count only if > 1
            if (count > 1) {

                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};