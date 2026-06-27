class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq; // stores indices
        vector<int> ans;

//intital window process
           for(int i = 0; i < k; i++){
            int element = nums[i];

            while(!dq.empty() && nums[dq.back()] <= element){
                dq.pop_back();
            }
            // insert current element
            dq.push_back(i);
        }

        ans.push_back( nums[dq.front()] );//

        for(int i=k;i<n;i++){
             int element = nums[i];

             if(!dq.empty() && dq.front()<=i-k ) {dq.pop_front();}

               while(!dq.empty() && nums[dq.back()] <= element){
                dq.pop_back();
            }

              dq.push_back(i);
   ans.push_back( nums[dq.front()] );//

        }


   return ans; }
};