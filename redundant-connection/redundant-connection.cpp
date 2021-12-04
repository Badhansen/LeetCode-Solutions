class UnionFind{
private:
    struct Node{
        int parent;
        int rank;
    };
    vector<Node> nodes;
public:
    UnionFind(int n){
        nodes.resize(n);
        for(int i = 0; i < n; i++){
            nodes[i].parent = i;
            nodes[i].rank = 0;
        }
    }
    int FindRoot(int r){
        if(nodes[r].parent == r)
            return r;
        return nodes[r].parent = FindRoot(nodes[r].parent);
    }
    bool Union(int a, int b){
        a = FindRoot(a);
        b = FindRoot(b);
        if(a != b){
            if(nodes[a].rank < nodes[b].rank)
                swap(a, b);
            nodes[b].parent = a;
            if(nodes[a].rank == nodes[b].rank)
                nodes[a].rank++;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind root(edges.size() + 1);
        for(auto &edge : edges){
            if(!root.Union(edge[0], edge[1]))
                return edge;
        }
        return {0, 0};
    }
};