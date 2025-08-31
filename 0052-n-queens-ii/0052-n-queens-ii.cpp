class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);       
        vector<bool> diag1(2*n, false);    
        vector<bool> diag2(2*n, false);    
        int count = 0;
        
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int col = 0; col < n; col++) {
                if (cols[col] || diag1[row+col] || diag2[row-col+n]) continue;
                
                cols[col] = diag1[row+col] = diag2[row-col+n] = true;
                backtrack(row + 1);
                cols[col] = diag1[row+col] = diag2[row-col+n] = false;
            }
        };
        
        backtrack(0);
        return count;
    }
};
