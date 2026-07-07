class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // The Checklists (Memory)
        // rows[i][j] means: "In row 'i', have we seen the number 'j+1'?"
        // We use size 9 for the 9 rows/cols/boxes, and size 9 for digits 1-9.
        int rows[9][9] = {0};
        int cols[9][9] = {0};

     // 3 rows of boxes, 3 columns of boxes, 9 possible digits inside
        int boxes[3][3][9] = {0};
        
        // Scan the board strictly once
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }
                
                // Convert the char '1'-'9' into an integer index 0-8
                int val = board[r][c] - '1';
                
                // RULE CHECK: Have we seen this number in this row, col, or box before?
              if (rows[r][val] == 1 || cols[c][val] == 1 || boxes[r / 3][c / 3][val] == 1) {
                    return false; 
                }
                
                // MARK AS SEEN: Update our clipboards
                rows[r][val] = 1;
                cols[c][val] = 1;
                 boxes[r / 3][c / 3][val] = 1;
            }
        }
        
        // If we checked every single number and found no collisions
        return true;
    }
};