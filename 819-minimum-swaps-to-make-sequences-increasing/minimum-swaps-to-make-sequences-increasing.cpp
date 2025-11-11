class Solution {
public:
int n;
  vector<vector<int>> t;

    inline int solve(int i,bool  prevSwapped,vector<int>& nums1, vector<int>& nums2){
        if(i==n) return 0;
        if(t[i][prevSwapped]!=-1) return t[i][prevSwapped];

        int prev1=-1,prev2=-1;
        if(i>0)  { prev1=nums1[i-1]; prev2=nums2[i-1];}
         if (prevSwapped) swap(prev1, prev2); //

        int ans=INT_MAX;
        // Option 1: no swap at i (valid only if strictly increasing)
        if (nums1[i] > prev1 && nums2[i] > prev2)
            ans = solve(i + 1, false,nums1,nums2);

        // Option 2: swap at i (valid only if after swapping it stays increasing)
        if (nums1[i] > prev2 && nums2[i] > prev1)
            ans=min(ans,1 + solve( i + 1, true,nums1,nums2))  ;//

           return t[i][prevSwapped]=ans;
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
         n=nums1.size();
     t.assign(n+1,vector<int>(2,-1));
       return solve(0,false,nums1,nums2);



    }
};