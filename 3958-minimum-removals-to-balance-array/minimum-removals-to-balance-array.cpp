class Solution {
        using ll = long long;
public:
    int minRemoval(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size(), ans = n-1, j = 0;
        for(int i = 0; i < n; i++) {
            while(j < n && (ll)v[j] <= (ll)k*v[i]) j++;
            ans = min(ans, i + n-j);
        }
        return ans;
    }
};