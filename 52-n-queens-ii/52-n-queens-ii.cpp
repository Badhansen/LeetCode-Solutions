class Solution {
public:
    int N;
    int mat[10][10];
    int isSafe(int r, int c){
        for(int i = 0; i < r; i++){
            if(mat[i][c]){
                return 0;
            }
        }
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
            if(mat[i][j]){
                return 0;
            }
        }
        for(int i = r, j = c; i >= 0 && j < N; i--, j++){
            if (mat[i][j]) {
                return 0;
            }
        }
        return 1;
    }
    int go(int r){
        if(r == N){
            return 1;
        }
        int ret = 0;
        for(int i = 0; i < N; i++){
            if(isSafe(r, i)){
                mat[r][i] = 1;
                ret += go(r + 1);
                mat[r][i] = 0;
            }
        }
        return ret;
    }
    int totalNQueens(int n) {
        N = n;
        memset(mat, 0, sizeof(mat));
        int ans = go(0);
        return ans;
    }
};