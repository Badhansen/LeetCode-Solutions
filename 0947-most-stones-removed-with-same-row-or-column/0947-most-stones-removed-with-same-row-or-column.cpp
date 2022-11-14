const int kMax = 1e4 + 5;

class Solution {
private:
    vector<int> visited;
public:
    void dfs(int src, vector<vector<int>>& stones) {
        visited[src] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] && (stones[src][0] == stones[i][0] || stones[src][1] == stones[i][1])) {
                dfs(i, stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        visited.resize(stones.size(), false);
        int result = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
                result++;
                dfs(i, stones);
            }
        }
        return stones.size() - result;
    }
};