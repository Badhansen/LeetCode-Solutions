class Solution {
private:
    set<int> level[1001];
    vector<int> gr[1001];
public:
    void dfs(int u, vector<bool>& vis, vector<int>& ans){
        vis[u] = true;
        for(int v : level[u]){
            if(vis[v] == false){
                ans.push_back(v);
                dfs(v, vis, ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> ind(n + 1, 0);
        for(auto edge : edges){
            ind[edge[1]]++;
            gr[edge[0]].push_back(edge[1]);
        }
        queue<int> qt;
        for(int i = 0; i < n; i++){
            if(ind[i] == 0){
                qt.push(i);
            }
        }
        while(!qt.empty()){
            int u = qt.front();
            qt.pop();
            for(auto v : gr[u]){
                level[v].insert(u);
                ind[v]--;
                if(ind[v] == 0){
                    qt.push(v);
                }
            }
        }
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            vector<int> ans;
            vector<bool> vis(n, false);
            dfs(i, vis, ans);
            sort(ans.begin(), ans.end());
            result.push_back(ans);
        }
        return result;
    }
};
