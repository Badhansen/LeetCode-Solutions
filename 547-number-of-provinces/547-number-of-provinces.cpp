class Solution {
public:
    void Dfs(int src, vector<vector<int>>& isConnected) {
        for (int dest = 0; dest < isConnected.size(); dest++) {
            if (isConnected[src][dest]) {
                isConnected[src][dest] = isConnected[dest][src] = 0; 
                Dfs(dest, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        for (int src = 0; src < isConnected.size(); src++) {            
            if (isConnected[src][src]) {
                Dfs(src, isConnected);
                result++;
            }
        }
        return result;
    }
};
/*
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 1);
        count = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int Find(int node){
        if(parent[node] == node) 
                    return node;
        return parent[node] = Find(parent[node]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a != b){
            if(rank[a] < rank[b]) 
                swap(rank[a], rank[b]);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
            count--;
        }
    }
    int GetPatent(int index){
        return parent[index];
    }
    int GetRank(int index){
        return rank[index];
    }
    int GetCount() {
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind root(n);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (isConnected[x][y]) {
                    root.Union(x, y); 
                }
            }
        }
        return root.GetCount();
    }
};
*/