#define MAX_N 55

class Solution {
private:
    struct Node{
        int time, row, col;
        Node(int t, int r, int c) : time(t), row(r), col(c) {}
        bool operator < (const Node& x) const {
            return time > x.time;
        }
    };
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    int n;
    priority_queue<Node> que;
    bool visited[MAX_N][MAX_N];
public:
    bool isValid(int r, int c){
        if(r >= 0 && r < n && c >= 0 && c < n)
            return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        que.push(Node(grid[0][0], 0, 0));
        visited[0][0] = true;
        int ans = 0;
        
        while(!que.empty()){
            Node node = que.top();
            que.pop();
            ans = max(ans, node.time);
            
            if(node.row == n - 1 && node.col == n - 1) return ans;
            
            for(int i = 0; i < 4; i++){
                int nrow = node.row + dirx[i], ncol = node.col + diry[i];
                if(isValid(nrow, ncol) && !visited[nrow][ncol]){
                    que.push(Node(grid[nrow][ncol], nrow, ncol));
                    visited[nrow][ncol] = true;
                }
            }
        }
        
        return ans;
    }
};

// Time: O(N^2 * log N), N = grid length
// Space: O(N^2)
/*
// @Author: KING-SEN
// 1 last try

#define MAX_N 55

class Solution {
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    bool visited[MAX_N][MAX_N];
    vector<pair<int, int>> levels[MAX_N * MAX_N];
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int time = grid[0][0];
        levels[time].push_back({0, 0});
        visited[0][0] = true;
        while(true){
            if(levels[time].size()){
                queue<pair<int, int>> que;
                for(auto &t : levels[time]){
                    que.push(t);
                }
                while(!que.empty()){
                    int row = que.front().first;
                    int col = que.front().second;
                    
                    if(row == n - 1 && col == n - 1) return time;
                    
                    que.pop();
                    
                    for(int i = 0; i < 4; i++){
                        int nrow = dirx[i] + row;
                        int ncol = diry[i] + col;
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                            if(grid[nrow][ncol] <= time){
                                que.push({nrow, ncol});
                                visited[nrow][ncol] = true;
                            } 
                            else levels[grid[nrow][ncol]].push_back({nrow, ncol});
                        }
                    }   
                }
            }
            time++;
        }
    }
};

// Time: O(N ^ 2), N = grid length
// Space: O(N ^ 2)
*/
