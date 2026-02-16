class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;++i){
            ans|=(n&1);
            n>>=1;
            if(i!=31) ans<<=1;
        }
        return ans;
    }
};
