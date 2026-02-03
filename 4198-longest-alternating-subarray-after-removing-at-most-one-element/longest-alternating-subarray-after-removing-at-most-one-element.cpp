class Solution {
public:
    int longestAlternating(vector<int>& a) {
        int n = a.size();
        int left[n], right[n];
        left[0] = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] == a[i-1]) {
                left[i] = 1;
            }
            else if(i >= 2 && 1LL*(a[i-1] - a[i]) * (a[i-1] - a[i-2]) > 0) {
                left[i] = left[i-1] + 1;
            }
            else {
                left[i] = 2;
            }
        }
        reverse(a.begin(), a.end());
        right[0] = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] == a[i-1]) {
                right[i] = 1;
            }
            else if(i >= 2 && 1LL*(a[i-1] - a[i]) * (a[i-1] - a[i-2]) > 0) {
                right[i] = right[i-1] + 1;
            }
            else {
                right[i] = 2;
            }
        }
        reverse(a.begin(), a.end());
        reverse(right,right+n);

        int ans = 0;
        ans = *max_element(left, left + n);

        for(int i = 1; i < n-1; i++) {
            //can i delete i?
            int Left = 1;
            int Right=1;
            //(a[i-2] - a[i-1]) * (a[i+1] - a[i-1]) > 0
            //(a[i+2] - a[i+1]) * (a[i-1] - a[i+1]) > 0

            if(i >= 2 && 1LL*(a[i-2] - a[i-1]) * (a[i+1] - a[i-1]) > 0) {
              Left = left[i-1];
            }
            if(i < n-2 && 1LL*(a[i+2] - a[i+1]) * (a[i-1] - a[i+1]) > 0) {
                Right=right[i+1];
            }

            if(a[i-1] == a[i+1]) continue;
             ans = max(ans, Left+Right);
         
        }

        return ans;
    }
};