class Solution {
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
public:
    bool reachable(int time, vector<vector<int>>& grid){
        int n = grid.size();
        bool visited[n + 1][n + 1];
        memset(visited, false, sizeof visited);
        queue<pair<int, int>> que;
        visited[0][0] = true;
        que.push({0, 0});
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();            
            if(grid[row][col] <= time){
                
                if(row == n - 1 && col == n - 1) return true;
                
                for(int i = 0; i < 4; i++){
                    int nrow = dirx[i] + row;
                    int ncol = diry[i] + col;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                        que.push({nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
                }   
            }
        }
        
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0], high = n * n, ans;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(reachable(mid, grid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// Time: O(N^2 log N)
// Space: O(N^2)