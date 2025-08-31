class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
private:
    bool backtrack(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, r, c, d)) {
                            board[r][c] = d;
                            if (backtrack(board)) return true;
                            board[r][c] = '.'; 
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }
    
    bool isValid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == d) return false; 
            if (board[i][c] == d) return false; 
            int row = (r/3)*3 + i/3, col = (c/3)*3 + i%3;
            if (board[row][col] == d) return false; 
        }
        return true;
    }
};
