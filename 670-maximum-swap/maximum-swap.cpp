class Solution {
public:
    int maximumSwap(int n) {
        string s = to_string(n);

        vector<int> last(10, -1);

         // FIXED: use s.size()
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - '0'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';

            for (int j = 9; j > d; j--) {
                if (last[j] > i) {
                    swap(s[i], s[last[j]]);
                    return stoi(s);
                }
            }

           
        }

         return n;}
    };
