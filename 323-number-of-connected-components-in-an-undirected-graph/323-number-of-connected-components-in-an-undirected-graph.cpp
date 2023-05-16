// @Author: KING-SEN
// 1 last try

class Solution {
private:
    vector<int> parent;
    vector<int> size;
    int component;
public:
    int Find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = Find(parent[node]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a != b){
            component--;
            if (size[a] < size[b]) {
		        swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        component = n;
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }
        return component;
    }
};

// Time: O(E * iA(N)), E = number of edges, iA = Inverse ackermann function, N = number of nodes
// Space: O(N)