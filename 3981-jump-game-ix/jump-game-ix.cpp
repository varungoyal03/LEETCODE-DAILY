class Solution {
public:
    vector<int> maxValue(vector<int>& A) {
        int n = A.size();

        // Step 1: Build suffix minimum array
        vector<int> S = A;
        for (int i = n - 2; i >= 0; i--) {
            S[i] = min(S[i], S[i + 1]);
        }

        vector<int> ans;
        int mx = 0;  // max in current component

        for (int i = 0; i < n; i++) {
            mx = max(mx, A[i]);

            // If no edge can go further → component ends
            if (i == n - 1 || mx <= S[i + 1]) {
                // Fill entire component with mx
                int len = i + 1 - ans.size();
                while (len--) ans.push_back(mx);

                mx = 0; // reset for next component
            }
        }

        return ans;
    }
};