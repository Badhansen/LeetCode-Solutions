class Solution {
public:
    const int UNASSIGNED = 0;

    int grid[10][10];
    int n;
    bool isRowExist(int r, int num){
        int cnt = 0;
        for(int c = 0; c < n; c++){
            if(grid[r][c] == num) cnt++;
        }
        if(cnt == 1) return true;
        return false;
    }
    bool isColExist(int c, int num){
        int cnt = 0;
        for(int r = 0; r < n; r++){
            if(grid[r][c] == num) cnt++;
        }
        if(cnt == 1) return true;
        return false;
    }
    bool isBoxExist(int stRow, int stCol, int num){
        int cnt = 0;
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                if(grid[r + stRow][c + stCol] == num) cnt++;
            }
        }
        if(cnt == 1) return true;
        return false;
    }

    bool isSafe(int row, int col, int num){
        return isRowExist(row, num)
            && isColExist(col, num)
            && isBoxExist(row - (row % 3), col - (col % 3), num);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(grid, 0, sizeof(grid));
        n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') grid[i][j] = 0;
                else grid[i][j] = board[i][j] - '0';
            }
        }
        bool ret = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    ret &= isSafe(i, j, grid[i][j]);
                }
            }
        }
        return ret;
    }
};