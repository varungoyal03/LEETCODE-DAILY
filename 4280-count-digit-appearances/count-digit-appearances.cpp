class Solution {
public:
    int solve(int num, int dig)
    {
        int ans=0;
        while(num>0){
            int d = num%10;
            num/=10;
            if(d==dig) ans++;
        }
        return ans;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;

        for(auto x:nums){
            ans+=solve(x,digit);
        }

        return ans;
    }
};