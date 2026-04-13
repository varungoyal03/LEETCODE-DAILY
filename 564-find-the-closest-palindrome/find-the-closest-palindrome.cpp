class Solution {
public:
    typedef long long ll;

    long long createPalindrome(long long prefix, bool isEven) {
        string s = to_string(prefix);
        string res = s;
        if (!isEven)
            s.pop_back(); // odd
        reverse(s.begin(), s.end());
        res += s;
        return stoll(res);
    }
    string nearestPalindromic(string n) {
        int len = n.size();

        vector<ll> candidates;

        ll prefix = stoll(n.substr(0, (len + 1) / 2));
        bool isEven = (len % 2 == 0);

        for (long long i : {-1, 0, 1}) {
            // Valid in C++11 and later
            candidates.push_back(createPalindrome(prefix + i, isEven));
        }

        // Edge cases: n-1 digits and n+1 digits
        candidates.push_back(stoll("1" + string(len - 1, '0')) -
                             1);                                 // 10^(n-1) - 1
        candidates.push_back(stoll("1" + string(len, '0')) + 1); // 10^n + 1

        ll num = stoll(n);
        ll minDiff = LLONG_MAX;
        ll ans = 0;

        for (auto c : candidates) {
            if (c == num)
                continue;

            ll diff = abs(c - num);

            if (diff < minDiff) {
                minDiff = diff;
                ans = c;
            } else if (diff == minDiff) {
                ans = min(ans, (ll)c);
            }
        }

        return to_string(ans);
    }
};