class Solution {
public:
    int maxBalancedShipments(vector<int>& a) {
        int n=a.size();
int cnt=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1] ) {
                cnt++;
                i++;
            }
       
        }
        return cnt;
    }
};