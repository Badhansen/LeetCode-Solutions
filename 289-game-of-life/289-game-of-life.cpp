class Solution {
private:
    int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
public:
    int check(int a, int b, vector<vector<int>>& board){
        int ret = 0;
        for(int i = 0; i < 8; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            if(na >= 0 && na < board.size() && nb >= 0 && nb < board[0].size()){
                ret += board[na][nb];
            }
        }
        return ret;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int count = check(i, j, board);
                if(count < 2 || count > 3){
                    ans[i][j] = 0;
                }
                else if(count == 3){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = board[i][j];
                }
            }
        }
        board = ans;
    }
};