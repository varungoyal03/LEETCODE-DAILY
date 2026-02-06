class Solution {
public:
  const int M = 1e9 + 7;
    int countPartitions(vector<int>& a, int k) {
        int n=a.size();
        vector<int> dp(n+1,0);
        vector<int> suffix(n+2,0);

        dp[n]=1;
        suffix[n]=dp[n];

    multiset<int> ms;
    int j=n-1;
        for(int i=n-1;i>=0;i--){

            ms.insert(a[i]);
            while (*(ms.rbegin()) - *(ms.begin()) > k) {
                ms.erase(ms.find(a[j]));
                j--;
            }

            dp[i]=(suffix[i+1]-suffix[j+2]+M)%M;

            suffix[i]=(suffix[i+1]+dp[i])%M;

// i to j
///i+1to j+1 sum


        }
    return dp[0];}
};