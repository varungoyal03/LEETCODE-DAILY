class Solution {
public:
 int helper(string s , string t){
        int cnt = 0 , m = s.size();
        multiset<pair<char ,char>> st;

        for(int ind = 0 ; ind < m ; ind++){
            if(s[ind] == t[ind]) continue;


                auto it = st.find({t[ind] , s[ind]});
                if(it != st.end()){
                    st.erase(it);
                    cnt++;
                }
                else {
                    st.insert({s[ind] , t[ind]});
                }
            
        }
        int op1= cnt + st.size();
 

return op1;
    }

    int minOperations(string s1, string s2) {
        int n = s1.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int i = n-1; i >=0; i--) {
              string s = "" , t = "";
            for(int j = i; j <n; j++) {
                 s += s1[j] , t += s2[j];
                dp[i] = min(dp[i], dp[j+1] + helper(s, t));

                    reverse(s.begin(), s.end());
                dp[i] = min(dp[i], dp[j+1] + 1+helper(s, t));
                    reverse(s.begin(), s.end());
            
             
            }
        }
        return dp[0];
    }
};