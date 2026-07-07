
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Start the recursion explicitly at top-left: row 0, col 0
        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int row, int col) {

        // ==========================================
        // BASE CASE 1: We successfully passed the last row!
        // ==========================================
        if (row == 9) {
            return true;
        }

        // ==========================================
        // BASE CASE 2: The Wrap-Around
        // ==========================================
        // If we hit the end of the columns, jump to the next row at column 0.
        if (col == 9) {
            return solve(board, row + 1, 0);
        }

        // ==========================================
        // STEP 1: Skip pre-filled cells
        // ==========================================
        if (board[row][col] != '.') {
            // Strictly move forward to the next column
            return solve(board, row, col + 1);
        }

        // ==========================================
        // STEP 2: The Empty Cell Logic
        // ==========================================
        for (char c = '1'; c <= '9'; c++) {

            if (isValid(board, row, col, c)) {
                // CHOOSE
                board[row][col] = c;

                // EXPLORE (Move to the next column)
                if (solve(board, row, col + 1) == true) {
                    return true;
                }

                // UN-CHOOSE (Backtrack)
                board[row][col] = '.';
            }
        }

        // If no numbers 1-9 work, this path is a dead end.
        return false;
    }

    // (The isValid function remains exactly the same as before)
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
        }

        int startRow = row - (row % 3), startCol = col - (col % 3);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] ==c)
                    return false;

        return true;
    }
};