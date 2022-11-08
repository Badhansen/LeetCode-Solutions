// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0, row = board.size(), col = board[0].size();
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                if(board[x][y] == 'X'){
                    if(x == 0 && y == 0){
                        count++;
                        continue;
                    }
                    else if(x == 0) {
                        if (board[x][y - 1] == '.') count++;  
                    } 
                    else if(y == 0) {
                        if (board[x - 1][y] == '.') count++;
                    }
                    else {
                        if (board[x - 1][y] != 'X' && board[x][y - 1] != 'X') count++;
                    }
                }
            }
        }
        return count;
    }
};

// Time: O(R * C), R = number of rows C = number of columns
// Space: O(1)