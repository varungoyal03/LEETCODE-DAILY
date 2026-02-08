class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        long long len = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                len++;
            } else {
              
                ans += (len +1)*(len+2)/2 -(len+1);
                  len=0;
            }
            
        }

        ans += (len +1)*(len+2)/2 -(len+1);
        
        return ans;
    }
};