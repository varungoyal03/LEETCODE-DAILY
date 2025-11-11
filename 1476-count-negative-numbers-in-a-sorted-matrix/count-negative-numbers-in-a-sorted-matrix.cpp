class Solution {
public:

    int firstNegativeIndex(const vector<int>& row) {
        int lo = 0, hi = row.size() - 1;
        int firstNeg = row.size(); // default means no negative

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (row[mid] < 0) {
                firstNeg = mid;
                hi = mid - 1;  // look to the left for earlier negative
            } else {
                lo = mid + 1;  // look to the right for negative
            }
        }
        return firstNeg;
    }


    int countNegatives(vector<vector<int>>& grid) {
            int totalNeg = 0;
        for (const auto& row : grid) {
            int idx = firstNegativeIndex(row);
            totalNeg += (row.size() - idx);
        }
        return totalNeg;
    }
};