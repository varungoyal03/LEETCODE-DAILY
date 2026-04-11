class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int countNeg=0;
        int minNumber=1e9;
        long long sum=0;

        for(auto &r:matrix){
            for(auto &x:r){
                sum+=abs(x);
                countNeg+=(x<0);
                minNumber=min(minNumber,abs(x));

            } 
        }

        if(countNeg&1) {
            return sum-2*minNumber;
        }

        return sum;
        
    }
};

    // even neg: all postve
    //   odd neg :1 neg ,1 number in entire matrix make -ve