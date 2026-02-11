class Solution {
      const int M = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
         hFences.push_back(1);
        vFences.push_back(1);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.push_back(m);
        vFences.push_back(n);

        vector<bool> hedges(m+1,false);
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = 0; j < i; j++) {
                hedges[hFences[i] - hFences[j]]=1;
            }
        }

        long long maxi = 0, x;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = 0; j < i; j++) {
                x = vFences[i] - vFences[j];
                
                if (x<=m && hedges[x])   maxi = max(maxi, x);
            }
        }

           if (maxi == 0)
            return -1;

            return (maxi*maxi)%M;




    
    }
};

// Given these fences, find the maximum area of a square formed by selecting four fences.”
