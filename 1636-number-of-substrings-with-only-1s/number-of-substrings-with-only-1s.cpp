class Solution {
public:
int MOD = 1e9 + 7;
typedef long long ll;
    int numSub(string s) {

ll ans=0;
int streak=0;
        for(auto ch:s){
            if(ch=='1') {
                streak++;
                ans=(ans+streak)%MOD;
            }
            else{
                streak=0;
            }
        }
   
   return ans%MOD; }
};