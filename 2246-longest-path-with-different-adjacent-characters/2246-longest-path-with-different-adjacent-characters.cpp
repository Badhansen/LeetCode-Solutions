class Solution {
private:
    vector<vector<int>> graph;
    int answer = 0;
public:
    int dfs(int u, int pr, string &s){
        int big1 = 0, big2 = 0;
        for(int v : graph[u]){
            if(v == pr){
                continue;
            }
            int curr = dfs(v, u, s);
            if(s[u] != s[v]){
                if(curr > big2){
                    big2 = curr;
                }
                if(big2 > big1){
                    swap(big1, big2);
                }
            }
        }
        answer = max(answer, big1 + big2 + 1);
        return big1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int len = parent.size();
        graph.resize(len + 1);
        for(int i = 1; i < len; i++){
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        dfs(0, 0, s);
        return answer;
    }
};
