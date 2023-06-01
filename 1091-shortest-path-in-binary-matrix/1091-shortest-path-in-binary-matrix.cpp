class Solution {
public:
    int solve(int n, int m, int x, int y){
        if(x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] || grid[n - 1][m - 1]) 
            return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
        int y[8] = {1, -1, -1, 0, 1, -1, 0, 1};
        queue<pair<int, int>> qt;
        qt.push({0, 0});
        vis[0][0] = true;
        int count = 1;
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                auto it = qt.front();
                qt.pop();
                //cout << it.first << " " << it.second << endl;
                if(it.first == n - 1 && it.second == m - 1)
                    return count;
                for(int i = 0; i < 8; i++){
                    if(solve(n, m, it.first + x[i], it.second + y[i]) 
                       && vis[it.first + x[i]][it.second + y[i]] == false 
                       && grid[it.first + x[i]][it.second + y[i]] == 0){
                        qt.push({it.first + x[i], it.second + y[i]});
                        vis[it.first + x[i]][it.second + y[i]] = true;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};