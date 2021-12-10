// @Author: KING-SEN
// Programming Language Used: C++

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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        UnionFind root(len);
        vector<int> ans1, ans2;
        unordered_map<int, int> seen;
        
        for(auto &edge : edges){
            if(seen[edge[1]] > 0){
                ans1.push_back(seen[edge[1]]);
                ans1.push_back(edge[1]);
                ans2 = edge;
                break;
            }
            seen[edge[1]] = edge[0];
        }
        
        for(auto &edge : edges){
            if(ans2 == edge)
                continue;
            if(!root.Union(edge[0], edge[1]))
                return ans1.size() == 0 ? edge : ans1;
        }
        
        return ans2;
    }
};

// Here, assume that, N = Number of Nodes
// Time Complexity: O(N * IN(N)) ~ O(N)
// Space Complexity: O(N), The current construction of the graph has at most N nodes.
