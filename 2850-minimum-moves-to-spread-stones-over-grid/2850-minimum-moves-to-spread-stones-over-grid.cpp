class Solution {
    vector<vector<int>> check = {{1,1,1},{1,1,1},{1,1,1}};
public:
    int minimumMoves(vector<vector<int>>& grid) {
        if (check == grid) {
            return 0;
        }
        int ans = INT_MAX;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (grid[r][c] == 0 && grid[i][j] > 1) {
                            grid[r][c]++, grid[i][j]--;
                            ans = min(ans, abs(r - i) + abs(c - j) + minimumMoves(grid));
                            grid[r][c]--; grid[i][j]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
