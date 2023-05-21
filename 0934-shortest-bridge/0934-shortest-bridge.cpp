class Solution {
public:
    int row, column;
    vector<vector<int>> direction {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    bool IsValid(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < column) {
            return true;
        }
        return false;
    }
    void Dfs(int x, int y, vector<vector<int>>& grid, queue<array<int, 2>>& sources) {
        sources.push({x, y});
        grid[x][y] = 2;
        for (auto dir : direction) {
            int new_x = dir[0] + x;
            int new_y = dir[1] + y;
            if (IsValid(new_x, new_y)) {
                if (grid[new_x][new_y] == 1) {
                    Dfs(new_x, new_y, grid, sources);
                }
            }
            
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        row = grid.size(), column = grid[0].size();
        queue<array<int, 2>> sources;
        bool called = false;
        for (int i = 0; i < row && !called; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] && !called) {
                    Dfs(i, j, grid, sources);
                    called = true;
                }
            }
        }
        int flipcount = 0;
        while (!sources.empty()) {
            int size = sources.size();
            queue<array<int, 2>> reference;
            for (int i = 0; i < size; i++) {
                array<int, 2> element = sources.front();
                sources.pop();
                for (auto dir : direction) {
                    int x = element[0] + dir[0];
                    int y = element[1] + dir[1];
                    if (IsValid(x, y)) {
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            reference.push({x, y});
                        }
                        if (grid[x][y] == 1) {
                            return flipcount;
                        }
                    }
                }
            }
            flipcount++;
            sources = reference;
        }
        return -1;
    }
};
