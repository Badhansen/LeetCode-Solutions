class Solution {
private:
    vector<int> parent;
    vector<int> size;
public:
    int Find(int p) {
        if (p == parent[p]) {
            return p;
        }
        return parent[p] = Find(parent[p]);
    }
    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];           
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        vector<vector<int>> graph(n);
        map<int, vector<int>> valToIndex;
        int answer = 0;
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            valToIndex[vals[i]].push_back(i);
        }
        for (auto [key, val] : valToIndex) {
            for (auto src : val) {
                for (auto node : graph[src]) {
                    if (vals[node] <= vals[src]) {
                        Union(node, src);
                    }
                }
            }
            map<int, int> count;
            for (auto src : val) {
                count[Find(src)]++;
                answer += count[Find(src)];
            }
        }
        return answer;
    }
};