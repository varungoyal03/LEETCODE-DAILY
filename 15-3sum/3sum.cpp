
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // OPTIMIZATION: Skip duplicate 'i' values to save time
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            set<int> seen;
            
            // FIX 1: Change boundary from 'n - 1' to 'n'
            for (int j = i + 1; j < n; j++) {

                int x = -(nums[i] + nums[j]);

                if (seen.count(x)) {
                    // FIX 2: Insert 'x' in the middle so the triplet is sorted
                    st.insert({nums[i], x, nums[j]});
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};