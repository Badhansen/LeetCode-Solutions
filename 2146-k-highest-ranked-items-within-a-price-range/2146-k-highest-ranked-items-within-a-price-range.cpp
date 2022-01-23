struct Node{
    int dis;
    int price;
    int row, col;
    Node(int d, int p, int r, int c){
        dis = d, price = p, row = r, col = c;
    }
    bool operator < (const Node& a) const{
        if(dis == a.dis){
            if(price == a.price){
                if(row == a.row){
                    return col > a.col;
                }
                return row > a.row;
            }
            return price > a.price;
        }
        return dis > a.dis;
    }
};
class Solution {
private:
    vector<int> x = {0, 0, 1, -1};
    vector<int> y = {1, -1, 0, 0};
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0) return false;
        return true;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> qt;
        vector<vector<int>> dis(n + 1, vector<int>(m + 1, INT_MAX));
        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
        qt.push({start[0], start[1]});
        dis[start[0]][start[1]] = 0;
        vis[start[0]][start[1]] = true;
        priority_queue<Node> kItem;
        if(grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]){
            kItem.push(Node(dis[start[0]][start[1]], grid[start[0]][start[1]], start[0], start[1]));
        }
        while(!qt.empty()){
            auto fr = qt.front();
            qt.pop();
            for(int i = 0; i < 4; i++){
                int nx = x[i] + fr.first;
                int ny = y[i] + fr.second;
                if(isValid(nx, ny, n, m, grid) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    dis[nx][ny] = dis[fr.first][fr.second] + 1;
                    qt.push({nx, ny});
                    if(grid[nx][ny] >= pricing[0] && grid[nx][ny] <= pricing[1]){
                        kItem.push(Node(dis[nx][ny], grid[nx][ny], nx, ny));
                    }
                }
            }
        }
        vector<vector<int>> ans;
        int idx = 0;
        while(!kItem.empty() && idx < k){
            auto item = kItem.top();
            kItem.pop();
            ans.push_back({item.row, item.col});
            idx++;
        }
        return ans;
    }
};