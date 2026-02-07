class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 1e9 + 7;
        map<int, int> suffix;
        map<int, int> prefix;
        for(auto x : nums) suffix[x] += 1;
        long long ans = 0;

        for(auto x : nums){
            suffix[x] -= 1;
            ans += 1LL* prefix[2 * x] * suffix[2 * x];
            ans%=M;
            prefix[x] += 1;
        }
        return ans % M;
    }
};


// [6,6,3,6,6] // ans is 4
//[0,0,0,0] ANS IS 5