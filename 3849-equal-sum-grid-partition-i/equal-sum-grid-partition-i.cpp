class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        long long  totalSum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                totalSum += grid[i][j];
            } }

        if(totalSum%2 !=0) return false;

 long long  hSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                hSum += grid[i][j];
            } 

            if(hSum==totalSum/2) return true;
        }


long long  vSum = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                vSum += grid[i][j];
            } 

            if(vSum==totalSum/2) return true;
        }



return false;
    }
};