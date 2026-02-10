class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs.size(), m = strs[0].size(), count = 0;
        vector<bool> done(n,false); // done order of str[i] and str[i + 1]

        for (int col = 0;col < m; ++col) {
            bool check = true;
            for (int row = 0; row < n - 1; ++row) {
                if (!done[row] && strs[row][col] > strs[row + 1][col]) {
                    ++ans;
                    check = false;
                    break;
                }
            }
            
            if (check) {
                for (int j = 0; j < n - 1; ++j) {
                    if (!done[j] && strs[j][col] < strs[j + 1][col]) {
                        done[j] = true;
                        ++count;
                    }
                }
                if (count == n - 1) break;
            }
        }

        return ans;
    }
};