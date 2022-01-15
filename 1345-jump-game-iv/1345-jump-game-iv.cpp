class Solution {
private:
    unordered_map<int, set<int>> graph;
    vector<bool> vis;
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size(), ans = 0;
        vis.resize(len, false);
        for(int i = 0; i < len; i++){
            graph[arr[i]].insert(i);
        }
        vector<int> curr;
        curr.push_back(0);
        vis[0] = true;
        while(!curr.empty()){
            vector<int> nxt;
            for(auto &u : curr){
                if(u == len - 1) return ans;
                vector<int> path(graph[arr[u]].begin(), graph[arr[u]].end());
                path.push_back(u - 1);
                path.push_back(u + 1);
                for(auto &v : path){
                    if(v > 0 && u < len && !vis[v]){
                        vis[v] = true;
                        nxt.push_back(v);
                    }
                } 
                graph[arr[u]].clear();
            }
            curr = nxt;
            ans++;
        }
        return ans;
    }
};