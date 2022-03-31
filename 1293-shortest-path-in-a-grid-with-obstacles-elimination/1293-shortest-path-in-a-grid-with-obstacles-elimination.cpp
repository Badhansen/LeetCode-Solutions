// Please don't solve this one
// @Author: KING-SEN

struct Node{
    int u, v, k, dis;
    Node(int u, int v, int k, int dis){
        this->u = u, this->v = v, this->k = k, this->dis = dis;
    }
};
struct compare{
    bool operator()(const Node& a, const Node& b){
        if(a.dis == b.dis){
            return a.k < b.k;
        }
        return a.dis > b.dis;
    }
};
class Solution {
private:
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<Node, vector<Node>, compare> que;
        vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, 0));
        visited[row - 1][col - 1] = 1;
        if(grid[row - 1][col - 1] == 1){
            que.push(Node(row - 1, col - 1, k - 1, 0));
            k--;
        }
        else{
            que.push(Node(row - 1, col - 1, k, 0));
        }
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                auto node = que.top();
                que.pop();
                if(node.u == 0 && node.v == 0){
                    return level;
                }
                for(int i = 0; i < 4; i++){
                    int nx = dirX[i] + node.u;
                    int ny = dirY[i] + node.v;
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && visited[nx][ny] == 0){
                        if(grid[nx][ny]){
                            if(node.k > 0){
                                visited[nx][ny] = 1;
                                que.push(Node(nx, ny, node.k - 1, node.dis + 1));
                            }
                        }
                        else{
                            visited[nx][ny] = 1;
                            que.push(Node(nx, ny, node.k, node.dis + 1));
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
