class Solution {
public:
 vector<int> t;
    int solve(int i,vector<int>& nums, int k) {
        int n=nums.size();
        if(i==n-1) return nums[i];//

        int ub=min(n - 1, i + k);

        int ans=INT_MIN;
        for(int j=i+1;j<=ub;j++){
          ans=max(ans, nums[i] + solve(j,nums,k));  
        }
        return t[i]=ans;
    }

    int N2_maxResult(vector<int>& nums, int k) {

        int n=nums.size();
        t.assign(n,-1);
    //    return solve(0,nums,k);
        t[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            

                int ub=min(n - 1, i + k);

                int ans=INT_MIN;
                for(int j=i+1;j<=ub;j++){
                ans=max(ans, nums[i] + t[j]);  
                }
                t[i]=ans;

        }
  return t[0];  }


//optimised
      int maxResult(vector<int>& nums, int k) {

        int n=nums.size();
        t.assign(n,-1);
    //    return solve(0,nums,k);
        t[n-1]=nums[n-1];

        multiset<int,greater<int>> s;
        // s.insert(nums[n-1]);

        for(int i=n-2;i>=0;i--){
            

                int ub= i+k;
                if(ub+1<n) s.erase(  s.find(t[ub+1]) );
                s.insert(t[i+1]);  //insert t not nums

             
                t[i]=nums[i]+*s.begin();

        }

        cout << "\nFinal dp array t: ";
        for (int x : t) cout << x << " ";
        cout << "\n";
  return t[0];  }





};