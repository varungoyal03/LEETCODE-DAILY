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

        for(int i=0;i<temp.size();i++){//
            int x=temp[i]; //
           int index= upper_bound(temp.begin(),temp.end(),x+n-1)-temp.begin();  //temp
           int elemntsInRange=index-i;
         
       
            ans=min(ans,n-elemntsInRange);
           
        }


return ans;



    }
};


//[x,x+n-1]

    // longest continue appproch not wokred
