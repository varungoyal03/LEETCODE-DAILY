class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n=nums.size();

        int h=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
        int l=h-1;


        while(k--){
            if(l<0) h++;
            else if(h>=n) l--;
            else if(abs(nums[l] - x) <= abs(nums[h] - x)){
                l--;
                
            }
            else{
                h++;
             
            }
          
        }
        
        //l+1 to h-1

        return vector<int> (nums.begin()+l+1,nums.begin()+h);
    }
};



