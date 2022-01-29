class Solution {
public:
    int n, m;
    int count = 0;
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(grid[i][j]){
            grid[i][j] = 0;
            count++;
            if(i + 1 < n) dfs(i + 1, j, grid);
            if(j + 1 < m) dfs(i, j + 1, grid);
            if(i - 1 >= 0) dfs(i - 1, j, grid);
            if(j - 1 >= 0) dfs(i, j - 1, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    count = 0;
                    dfs(i, j, grid);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};