class Solution {
public:
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int maxDist = 0;
    int n = nums1.size(), m = nums2.size();

    for (int i = 0; i < n; i++) {
        int low = i, high = m - 1;
        int bestJ = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums2[mid] >= nums1[i]) {
                bestJ = mid;
                low = mid + 1; // Try to find a larger j to the right
            } else {
                high = mid - 1; // nums2[mid] is too small, look left
            }
        }

        if (bestJ != -1) {
            maxDist = max(maxDist, bestJ - i);
        }
    }
    return maxDist;
}
};