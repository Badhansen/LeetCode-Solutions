class Solution {
public:
    vector<vector<string>> ans;
    void solve(int row, vector<bool> &cols, vector<bool> &nDiagonal,
                vector<bool> &rDiagonal, int &n, vector<string> &res){
        if(row == n){
            ans.push_back(res);
            return;
        }
        for(int col = 0; col < n; col++){
            if(!cols[col] && !nDiagonal[row - col + n - 1] && !rDiagonal[row + col]){
                cols[col] = 1;
                nDiagonal[row - col + n - 1] = 1;
                rDiagonal[row + col] = 1;
                res[row][col] = 'Q';
                
                solve(row + 1, cols, nDiagonal, rDiagonal, n, res);
                
                cols[col] = 0;
                nDiagonal[row - col + n - 1] = 0;
                rDiagonal[row + col] = 0;
                res[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, 0), nDiagonal(2 * n, 0), rDiagonal(2 * n, 0);
        vector<string> res;
        res.resize(n);
        for(int i = 0; i < n; i++){
            res[i].resize(n, '.');
        }
        solve(0, cols, nDiagonal, rDiagonal, n, res);
        return ans;
    }
};