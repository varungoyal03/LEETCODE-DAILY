class Solution {
public:
 using T = tuple<int, int, int>;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();

        priority_queue<T,vector<T>,greater<T>> pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0,0});

        vector<vector<int>> ans;

        while(!pq.empty() &&k--){
            auto top=pq.top(); pq.pop();   

            int sum=get<0>(top);
            int i=get<1>(top);
            int j=get<2>(top);

            ans.push_back({nums1[i],nums2[j]});

            if(i + 1 < nums1.size() && !visited.count({i+1, j})) {
                pq.push({nums1[i+1] + nums2[j], i+1, j});
                visited.insert({i+1, j});
            }

            if(j + 1 < nums2.size() && !visited.count({i, j+1})) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            }


        }


return ans;
        
    }
};