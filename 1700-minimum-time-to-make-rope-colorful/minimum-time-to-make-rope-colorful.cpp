class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int maxi = neededTime[0];
        int sum = accumulate(neededTime.begin(), neededTime.end(), 0);

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {

                maxi = max(maxi, neededTime[i]);

            } else {
                sum -= maxi;
                maxi = neededTime[i];
            }
        }
        sum -= maxi;

        return sum;
    }
};

