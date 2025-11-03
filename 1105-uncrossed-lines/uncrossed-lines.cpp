class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
vector<int>  curr(m+1, 0);
         vector<int>  prev(m+1, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(nums1[i]==nums2[j])
                    curr[j+1]=1+prev[j];

                else 
                curr[j+1]=max(prev[j+1],curr[j]) ;   
                
            }
    prev=curr;
        }
        return prev[m];
    }
};