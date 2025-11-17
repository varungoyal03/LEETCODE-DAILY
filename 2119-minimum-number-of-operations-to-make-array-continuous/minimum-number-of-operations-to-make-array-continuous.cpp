class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> s(nums.begin(),nums.end());
        vector<int> temp;
        
        for(auto x:s){
            temp.push_back(x);
                }
       int  ans=n;

int r=0;
        for(int l=0;l<temp.size();l++){//
        int x=temp[l];

         while(r<temp.size() && temp[r]<=x+n-1) r++;
            int elemntsInRange=r-l;

            ans=min(ans,n-elemntsInRange);
           
        }


return ans;



    }
};


//[x,x+n-1]

    // longest continue appproch not wokred
