class Solution {
public:
int MOD=1e9+7;


    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        using ll=long long;
     const int MOD = 1e9 + 7;
        sort(packages.begin(), packages.end());
        int n = packages.size();

ll sumPackages=0;
   for (int a : packages)
            sumPackages += a;

      

ll ans=LLONG_MAX;

        for (auto &b:boxes){
            sort(b.begin(), b.end());

            // Skip if supplier can't fit largest package
            if (b.back() < packages.back()) continue; 

            ll waste = 0;
            int prev = -1;
            for(int box:b){
            int i=upper_bound(packages.begin(), packages.end(),box)-packages.begin() -1;
            if(i==-1) continue;//
        


                  

        ll  totalBoxSpace = 1LL*(i-prev)*box ;    // 
       
            waste=(waste+    totalBoxSpace  ) ;
            prev=i;
            if(prev==n-1 )break;//
            }

            ans=min(ans,waste-sumPackages);//
        }
            
   return ans==LLONG_MAX?-1:ans%MOD;         }


};