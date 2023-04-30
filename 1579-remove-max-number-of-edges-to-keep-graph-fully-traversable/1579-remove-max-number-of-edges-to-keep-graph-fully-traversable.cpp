class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
    int components;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        components = n;
    }
    int FindRoot(int r){
        if(parent[r] == r)
            return r;
        return parent[r] = FindRoot(parent[r]);
    }
    int Union(int a, int b){
        a = FindRoot(a);
        b = FindRoot(b);
        if(a != b){
            if (size[a] < size[b])
		        swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
            return 1;
        }
        return 0;
    }
    int getSize(int index){
        return size[index];
    }
    int getParent(int index){
        return parent[index];
    }
    bool isConnected() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        for (auto &edge : edges) {
            if (edge[0] == 3) {
                edgesRequired += (alice.Union(edge[1] - 1, edge[2] - 1) | bob.Union(edge[1] - 1, edge[2] - 1));
            }
        }
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                edgesRequired += alice.Union(edge[1] - 1, edge[2] - 1);
            } else if (edge[0] == 2) {
                edgesRequired += bob.Union(edge[1] - 1, edge[2] - 1);
            }
        }
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        return -1;
    }
};