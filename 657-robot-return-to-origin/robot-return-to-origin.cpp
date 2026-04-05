class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;

        for(auto &ch:moves){
            i+=(ch=='U');
            i-=(ch=='D');

            j+=(ch=='R');
            j-=(ch=='L');


        }

        return i==0 && j==0;    }
};