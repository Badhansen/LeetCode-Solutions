class UnionFind{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++){
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
            if(rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> detectCycle(int n, vector<vector<int>> &edges, vector<int> skipList = {}){
        UnionFind root(n);
        for(auto &edge : edges){
            if(edge == skipList) 
                continue;
            if(!root.Union(edge[0], edge[1])){
                return edge;
            }
        }
        return {-1, -1};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<int> inDegree(len + 1, 0);
        int has2InDegree = -1;
        
        for(auto &edge : edges){
            inDegree[edge[1]]++;
            
            if(inDegree[edge[1]] == 2){
                has2InDegree = edge[1];
                break;
            }
        }
        
        if(has2InDegree == -1){
            return detectCycle(len, edges);
        }
        for(int i = len - 1; i >= 0; i--){
            if(edges[i][1] == has2InDegree){
                if(detectCycle(len, edges, edges[i])[0] == -1)
                    return edges[i];
            }
        }
        return {};
    }
};