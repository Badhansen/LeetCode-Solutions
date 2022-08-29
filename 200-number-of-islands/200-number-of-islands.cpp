class Solution {
public:
    bool visit[1001][1001];
    int r, c;
    bool rec(vector<vector<char>>& grid, int i, int j){
        if(i >= 0 && i < r && j >= 0 && j < c && visit[i][j] == false && grid[i][j] == '1') return true;
        return false;
    }
    void dfs(vector<vector<char>> &grid, int u, int v){
        if(visit[u][v]) return;
        visit[u][v] = true;
        //cout << u << " " << v << endl;
        if(rec(grid, u, v + 1)) dfs(grid, u, v + 1);
        if(rec(grid, u, v - 1)) dfs(grid, u, v - 1);
        if(rec(grid, u + 1, v)) dfs(grid, u + 1, v);
        if(rec(grid, u - 1, v)) dfs(grid, u - 1, v);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        r = grid.size();
        c = grid[0].size();
       
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                visit[i][j] = false;
            }
        }
        int cnt = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(visit[i][j] == false && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};