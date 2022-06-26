class Solution {
private:
    vector<vector<int>> graph;
    vector<int> subtreeXor;
    vector<vector<bool>> isAncestor;
public:
    int getScore(int score1, int score2, int score3){
        int minScore = min({score1, score2, score3});
        int maxScore = max({score1, score2, score3});
        return maxScore - minScore;
    }
    void makeAncestor(int src, int par, const int root){
        isAncestor[root][src] = true;
        for(auto v : graph[src]){
            if(v == par) continue;
            makeAncestor(v, src, root);
        }
    }
    void dfs(int src, int par, vector<int>& nums){
        subtreeXor[src] = nums[src];
        makeAncestor(src, par, src);
        for(auto v : graph[src]){
            if(v == par) continue;
            dfs(v, src, nums);
            subtreeXor[src] ^= subtreeXor[v];
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.resize(n);
        subtreeXor.resize(n, 0);
        isAncestor.resize(n, vector<bool>(n, false));
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0, 0, nums);
        int ans = INT_MAX, score1 = 0, score2 = 0, score3 = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i == j) continue;
                if(isAncestor[i][j]){
                    score1 = subtreeXor[j];
                    score2 = subtreeXor[j] ^ subtreeXor[i];
                    score3 = subtreeXor[0] ^ score1 ^ score2;
                }
                else if(isAncestor[j][i]){
                    score1 = subtreeXor[i];
                    score2 = subtreeXor[i] ^ subtreeXor[j];
                    score3 = subtreeXor[0] ^ score1 ^ score2;
                }
                else{
                    score1 = subtreeXor[i];
                    score2 = subtreeXor[j];
                    score3 = subtreeXor[0] ^ score1 ^ score2;
                }
                ans = min(ans, getScore(score1, score2, score3));
            }
        }
        return ans;
    }
};