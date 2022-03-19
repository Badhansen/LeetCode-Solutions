// @Author: KING-SEN

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int player = 1, n = 3;
        vector<int> rows(n, 0), cols(n, 0);
        int diag = 0, antiDiag = 0;
        for(auto m : moves){
            int row = m[0];
            int col = m[1];
            rows[row] += player;
            cols[col] += player;
            if(row == col){
                diag += player;
            }
            if(row + col == n - 1){
                antiDiag += player;
            }
            if(abs(rows[row]) == n || abs(cols[col]) == n ||
              abs(diag) == n || abs(antiDiag) == n){
                return player == 1 ? "A" : "B";
            }
            player *= -1;
        }
        if(moves.size() < 9){
            return "Pending";
        }
        return "Draw";
    }
};
