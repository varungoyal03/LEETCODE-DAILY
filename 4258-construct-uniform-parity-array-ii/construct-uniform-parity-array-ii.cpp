class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int min_odd = INT_MAX ;
        int min_even = INT_MAX - 1;

        for(int i = 0; i < n; i++){
            if(nums1[i] & 1){
                min_odd = min(min_odd, nums1[i]);
            } else {
                min_even = min(min_even, nums1[i]);
            }
        }

        return min_odd == INT_MAX || min_even == INT_MAX-1   || min_even > min_odd;
    }
};