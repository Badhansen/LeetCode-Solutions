class Solution {
    int total = 1;
    int row, col;
    array<int, 2> start, end;
    int ans = 0;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    void dfs(int i, int j, vector<vector<int>> grid, vector<pair<int, int>> path) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == -1 || visited[i][j]) {
            return;
        }
        
        if (i == end[0] && j == end[1]) {
            ans += (path.size() == total);
            return;
        }
        for (auto d : dirs) {
            path.push_back({i, j});
            visited[i][j] = true;
            dfs(i + d[0], j + d[1], grid, path);
            path.pop_back();
            visited[i][j] = false;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        visited.resize(row, vector<bool> (col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    total++;
                } else if (grid[i][j] == 1) {
                    start[0] = i, start[1] = j;
                } else if (grid[i][j] == 2) {
                    end[0] = i, end[1] = j;
                }
            }
        }
        vector<pair<int, int>> path;
        dfs(start[0], start[1], grid, path);
        return ans;
    }
};