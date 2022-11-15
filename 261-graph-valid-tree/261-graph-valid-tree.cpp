// @Author: KING-SEN

class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int FindRoot(int r){
        if(parent[r] == r)
            return r;
        return parent[r] = FindRoot(parent[r]);
    }
    bool Union(int a, int b){
        a = FindRoot(a);
        b = FindRoot(b);
        if(a != b){
            if (size[a] < size[b])
		        swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
    int getSize(int index){
        return size[index];
    }
    int getParent(int index){
        return parent[index];
    }
};
class Solution {
private:
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind find_root(n);
        int components = n;
        for (auto e : edges) {
            if (find_root.Union(e[0], e[1])) {
                components--;
            } else {
                return false;
            }
        }
        return components == 1;
    }
};
/*
class Solution {
private:
    vector<bool> visited;
    vector<int> parent;
    vector<vector<int>> graph;
public:
    bool dfs(int v, int par) { // passing vertex and its parent vertex
        visited[v] = true;
        for (int u : graph[v]) {
            if(u == par) continue; // skipping edge to parent vertex
            if (visited[u]) {
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        graph.resize(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        if (dfs(0, -1)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
*/