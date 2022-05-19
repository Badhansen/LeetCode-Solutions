class Solution {
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    vector<vector<int>> graph;
    vector<int> indegree, dist;
    vector<bool> visited;
public:
    int dfs(int u){
        visited[u] = true;
        dist[u] = 1;
        for(int v : graph[u]){
            if(!visited[v]){
                dist[u] = max(dist[u], 1 + dfs(v));
            }
            else{
                dist[u] = max(dist[u], 1 + dist[v]);
            }
        }
        return dist[u];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int node = row * col;
        int ans = 0;
        graph.resize(node);
        indegree.resize(node, 0);
        dist.resize(node, 0);
        visited.resize(node, false);
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                for(int d = 0; d < 4; d++){
                    int x = dirx[d] + r;
                    int y = diry[d] + c;
                    if(x >= 0 && x < row && y >= 0 && y < col && matrix[r][c] < matrix[x][y]){
                        // int oneDindex = (row * collumn count) + column; // Indexes
                        int from = r * col + c;
                        int to = x * col + y;
                        graph[from].push_back(to);
                        indegree[to]++;
                    }
                }
            }
        }
        for(int i = 0; i < node; i++){
            if(indegree[i] == 0){
                fill(visited.begin(), visited.end(), false);
                dfs(i);
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};