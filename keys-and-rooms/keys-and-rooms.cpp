class Solution {
public:
    vector<bool> vis;
    void dfs(int u, vector<vector<int>> &rooms){
        vis[u] = true;
        for(int i = 0; i < rooms[u].size(); i++){
            int v = rooms[u][i];
            if(!vis[v]){
                dfs(v, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.assign(n + 1, false);
        dfs(0, rooms);
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(!vis[i]) flag = false;
        }
        return flag;
    }
};