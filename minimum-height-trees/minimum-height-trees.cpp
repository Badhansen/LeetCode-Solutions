class Solution {
private:
    vector<vector<int>> graph;
public:
    int bfs(int src, int n){
        vector<int> dis(n, 0);
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = 1;
            for(int v : graph[curr]){
                if(vis[v] == 0){
                    dis[v] = dis[curr] + 1;
                    q.push(v);
                }
            }
        }
        int maxDis = INT_MIN, vertex;
        for(int i = 0; i < n; i++){
            if(dis[i] > maxDis){
                maxDis = dis[i];
                vertex = i;
            }
        }
        return vertex;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int start = bfs(0, n);
        int end = bfs(start, n);
        vector<int> parent(n);
        vector<int> vis(n, 0);
        queue<int> q;
        parent[start] = -1;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = 1;
            for(int v : graph[curr]){
                if(vis[v] == 0){
                    parent[v] = curr;
                    q.push(v);
                }
            }
        }
        vector<int> path;
        while(end != -1){
            path.push_back(end);
            end = parent[end];
        }
        if(path.size() & 1){
            return {path[path.size() / 2]};
        }
        else{
            return {path[path.size() / 2], path[path.size() / 2 - 1]};
        }
    }
};

// Time Complexity: O(N), only 2 DFS calls is made each requiring O(N) time.
// Space Complexity: O(N)
