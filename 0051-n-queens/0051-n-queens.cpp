class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); 
        vector<bool> cols(n, false);            
        vector<bool> diag1(2*n, false);        
        vector<bool> diag2(2*n, false);         
        
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                solutions.push_back(board);
                return;
            }
            for (int col = 0; col < n; col++) {
                if (cols[col] || diag1[row+col] || diag2[row-col+n]) continue;
                
                board[row][col] = 'Q';
                cols[col] = diag1[row+col] = diag2[row-col+n] = true;
                
                backtrack(row + 1);
                
                board[row][col] = '.';
                cols[col] = diag1[row+col] = diag2[row-col+n] = false;
            }
        };
        
        backtrack(0);
        return solutions;
    }
};
