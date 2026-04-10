class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;
        for (auto& p : mp) {
            auto v = p.second;
            if (v.size() >= 3) {

                for (int i = 0; i <= v.size() - 3; i++) {
                    int dist = 2*abs(v[i] - v[i + 2]);

                        ans = min(ans, dist);
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};
