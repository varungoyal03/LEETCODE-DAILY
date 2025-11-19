class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
                unordered_map<string, int> patFreq;
        
        for (const auto& row : matrix) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) pattern += to_string(bit);
            } else {
                for (int bit : row) pattern += to_string(bit ^ 1);
            }
            patFreq[pattern]++;
        }

        int maxFreq=0;
        for(auto &p:patFreq){
            maxFreq=max(maxFreq,p.second);
        }

        return maxFreq;
    }
};