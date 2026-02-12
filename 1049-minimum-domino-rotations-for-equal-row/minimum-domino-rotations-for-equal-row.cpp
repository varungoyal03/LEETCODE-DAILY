class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        vector<int> temp{tops[0],bottoms[0]};
        
        for (int i = 0; i <2; ++i) {
                int val=temp[i];
            int top_swaps = 0, bottom_swaps = 0;
            bool valid = true;
                for (int i = 0; i < tops.size(); ++i) {
                if (tops[i] != val && bottoms[i] != val) {
                    valid = false;
                    break;
                }
                if (tops[i] != val) top_swaps++;
                if (bottoms[i] != val) bottom_swaps++;
            }
            if (valid)
                res = min(res, min(top_swaps, bottom_swaps));
        }
        return res == INT_MAX ? -1 : res;
    }
};