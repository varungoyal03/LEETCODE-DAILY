class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();

        vector<int> prevMin(n,INT_MAX);
        prevMin[0]=nums[0];
        for(int i=1;i<n;i++){
            prevMin[i]=min(prevMin[i-1],nums[i]);
        }

    set<int> s;
    s.insert(nums[n-1]);
        for(int j=n-2;j>=1;j--){
            if(prevMin[j-1]<nums[j]){
                auto it=s.upper_bound(prevMin[j-1]);

                if(it!=s.end() && *it<nums[j]) return true;

                     
            }

             s.insert(nums[j]);

        }

        return false;
    }
};