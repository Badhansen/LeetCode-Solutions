class Solution {
private:
    int row, col;  
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int totalOrng = 0;
        queue<pair<int, int>> que;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) que.push({i, j});
                else if(grid[i][j] == 1) totalOrng++;
            }
        }
        int ans = 0, count = 0;
        while(!que.empty()){
            int siz = que.size();
            bool flag = false;
            while(siz--){
                auto p = que.front();
                que.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x[i] + p.first;
                    int ny = y[i] + p.second;
                    if(isValid(nx, ny, grid)){
                        flag = true;
                        count++;
                        que.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            if(flag) ans++;
        }
        return count == totalOrng ? ans : -1;
    }
};