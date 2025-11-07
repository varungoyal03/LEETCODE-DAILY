class Solution {
public:
    using ll = long long;

    bool check(ll mid, vector<int> stations, int r, int k) {
        int n = stations.size();
        ll sum = 0;
        for (int i = 0; i <= r; i++) { // window till rth not r-1
            sum += stations[i];
        }
        if (sum < mid) {
            ll add = mid - sum;// ll add
            if (k < add)
                return false;
            k -= add;
            stations[r] += add;
            sum = mid;
        }

        for (int i = 1; i < n; i++) { //
            if (i - r - 1 >= 0)
                sum -= stations[i - r - 1];

            if (i + r < n)
                sum += stations[i + r];

            if (sum < mid) {
                ll add = mid - sum;
                if (k < add)
                    return false;
                k -= add;
                if (i + r < n)
                    stations[i + r] += add;
                else
                    stations[n - 1] += add; // clamp to last city

                sum = mid;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {

        // TTTTTTTTTTFFFFFFF
        ll low = *min_element(stations.begin(), stations.end());
        ll high = accumulate(stations.begin(), stations.end(), 0LL) + k;
        ll ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (check(mid, stations, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};