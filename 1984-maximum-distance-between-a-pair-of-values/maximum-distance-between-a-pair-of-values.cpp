class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size(); int n2=nums2.size();

    int  j = 0;
    int ans=0;


        for(int i=0;i<n1;i++){
            while(j<n2 && nums2[j]>=nums1[i]) j++;

            if(j>=i) ans=max(ans,j-i-1); 

        }

return ans;
    }
};