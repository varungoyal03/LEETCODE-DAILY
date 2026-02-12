class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int threshold) {
        int n=a.size();

        int count=0;
        int sum=0;
        int threshSum=threshold*k;
        for(int i=0;i<k;i++){
            sum+=a[i];
        }
        if(sum>=threshSum){
            count++;
        }
        for(int i=k;i<n;i++){
            sum+=a[i];
            sum-=a[i-k];
            if(sum>=threshSum){
                count++;
            }
        }

        return count;
    }
};




