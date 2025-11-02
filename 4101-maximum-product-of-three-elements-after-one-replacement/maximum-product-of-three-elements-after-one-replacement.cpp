class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int first=INT_MIN;
        int second=INT_MIN;

        for(auto &x:nums){
            x=abs(x);

            if(x>=first){
                second=first;
                first=x;
            }
            else if(x>second) second=x;
        }

        return 1LL*first*second*1e5;


    }
};