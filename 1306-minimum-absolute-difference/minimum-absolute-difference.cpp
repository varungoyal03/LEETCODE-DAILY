class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int  minDiff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
           vector<vector<int>> ans;

        for(int i=1;i<arr.size();i++){
            if(minDiff==(arr[i]-arr[i-1]) ) ans.push_back({arr[i-1],arr[i]});


            
        }
        return ans;
    }
};