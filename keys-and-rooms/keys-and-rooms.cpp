class Solution {
private:
    vector<bool> vis;
public:
    void dfs(int u, vector<vector<int>>& rooms){
        vis[u] = true;
        for(auto &v : rooms[u]){
            if(!vis[v])
                dfs(v, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vis.resize(len, false);
        dfs(0, rooms);
        for(int i = 0; i < len; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};