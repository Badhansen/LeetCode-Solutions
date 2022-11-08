// @Author: KING-SEN
// 1 last try

class Solution {
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
public:
    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = 'v';
        for(int d = 0; d < 4; d++){
            int nx = dirx[d] + x;
            int ny = diry[d] + y;
            if(nx >= 0 && nx < board.size() &&
               ny >= 0 && ny < board[0].size() && board[nx][ny] == 'X'){
                dfs(nx, ny, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                if(board[x][y] == 'X'){
                    ans++;
                    dfs(x, y, board);
                }
            }
        }
        return ans;
    }
};

/*
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
*/