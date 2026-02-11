class Solution {
public:
    int find(vector<int>& bars){//find max consecutive bars
        sort(bars.begin(), bars.end());

        int ans = 1, curr = 1;
        for (int i = 1; i < bars.size(); i++){
            if (bars[i] == bars[i - 1] + 1){
                curr++;
                ans = max(ans, curr);
            } else {
                curr = 1;
            }
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int side = 1 + min(find(hBars), find(vBars));//indepensent
        return side * side;
    }
};