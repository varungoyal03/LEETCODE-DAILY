class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> diagonals(n + m - 1);
    
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            diagonals[i + j].push_back(mat[i][j]);
        }
    }

    
    vector<int> result;
    for (int s = 0; s < diagonals.size(); s++) {
        
        if (s % 2 == 0) {
            reverse(diagonals[s].begin(), diagonals[s].end());
        }
        
     
        for (int val : diagonals[s]) {
            result.push_back(val);
        }
    }
    
    return result;

    }
};