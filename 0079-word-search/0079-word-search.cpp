
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};


class Solution {
public:
    int r, c;
    bool dfs(vector<vector<char>> &board, int a, int b, int pos, string word){
        if(board[a][b] != word[pos]) return false;
        if(pos == word.size() - 1) return true;
        board[a][b] = '$';
        bool res = false;
        for(int i = 0; i < 4; i++){
            int p = a + x[i];
            int q = b + y[i];
            if(p >= 0 && p < r && q >= 0 && q < c && res == false){
                res |= dfs(board, p, q, pos + 1, word);
            }
            if(res) return res;
        }
        board[a][b] = word[pos];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};