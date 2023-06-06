class Solution {
private:
    vector<int> parents;
    vector<int> sizes;
    int components;
public:
    int FindRoot(int node){
        if (node == parents[node]) {
            return node;
        }
        return parents[node] = FindRoot(parents[node]);
    }
    void Union(int a, int b) {
        a = FindRoot(a);
        b = FindRoot(b);
        if (a != b) {
            components--;
            if (sizes[a] < sizes[b]) {
				swap(a, b);
            }
            parents[b] = a;
            sizes[a] += sizes[b];
        }
    }
    int kruskal(vector<vector<int>>& connections){
        int minimumcost = 0;
        for(int i = 0; i < connections.size(); i++){
            int u = --connections[i][0];
            int v = --connections[i][1];
            int cost = connections[i][2];
            if (FindRoot(u) != FindRoot(v)){
                minimumcost += cost;
                Union(u, v);
            }
        }
        return components != 1 ? -1 : minimumcost;
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
        components = n;
        sort(connections.begin(), connections.end(), [](auto &a, auto &b) {
            return a[2] < b[2]; 
        });
        int cost = kruskal(connections);
        return cost;
    }
};