// @Author: KING-SEN
// 1 last try

class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int component;
public:
    int Find(int node){
        if(parent[node] == node) return node;
        return parent[node] = Find(parent[node]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a != b){
            component--;
            if(rank[a] < rank[b]) swap(rank[a], rank[b]);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);
        component = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }
        return component;
    }
};

// Time: O(E * iA(N)), E = number of edges, iA = Inverse ackermann function, N = number of nodes
// Space: O(N)