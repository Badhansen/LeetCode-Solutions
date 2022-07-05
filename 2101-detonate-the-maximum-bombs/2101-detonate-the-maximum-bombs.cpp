class Solution {
private:
    vector<vector<int>> graph;
public:
    int dfs(int src, bitset<100>& connections){
        if(!connections[src]){
            connections[src] = true;
            for(auto dest : graph[src]){
                dfs(dest, connections);
            }
        }
        return connections.count();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph.resize(n + 1);
        long long x, y, newx, newy, radius;
        int result = 0;
        for(int i = 0; i < n; i++){
            x = bombs[i][0], y = bombs[i][1], radius = (long long)bombs[i][2] * bombs[i][2];
            for(int j = 0; j < n; j++){
                newx = (x - bombs[j][0]), newy = (y - bombs[j][1]);
                if(newx * newx + newy * newy <= radius){
                    graph[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n && result < n; i++){
            result = max(result, dfs(i, bitset<100>() = {}));
        }
        return result;
    }
    ~Solution(){
        for(int i = 0; i < graph.size(); i++){
            graph[i].clear();
        }
    }
};