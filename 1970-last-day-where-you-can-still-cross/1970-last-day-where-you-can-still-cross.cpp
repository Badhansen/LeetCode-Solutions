class Solution {
public:
    vector<vector<int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool CanReachTheLastRow(set<pair<int, int>> &points, vector<vector<bool>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> qt;
        for (auto p : points) {
            visited[p.first][p.second] = true;
            qt.push(p);
        }
        while (!qt.empty()) {
            int r = qt.front().first;
            int c = qt.front().second;
            
            if (r == grid.size() - 1) {
                return true;
            }
            qt.pop();
            for (auto d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] && !grid[nr][nc]) {
                    visited[nr][nc] = true;
                    qt.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        for (auto &c : cells) {
            c[0]--, c[1]--;
        }
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        int start = 0, end = cells.size(), answer = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            set<pair<int, int>> paths;
            for (int i = 0; i < mid; i++) {
                grid[cells[i][0]][cells[i][1]] = true;
            }
            for (int i = 0; i < col; i++) {
                if (!grid[0][i]) {
                    paths.insert({0, i});
                }
            }
            if (CanReachTheLastRow(paths, grid)) {
                answer = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            for (int i = 0; i < mid; i++) {
                grid[cells[i][0]][cells[i][1]] = false;
            }
        }
        return answer;
    }
};