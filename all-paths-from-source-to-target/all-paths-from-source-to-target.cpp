class Solution {
public:
    vector<vector<int>> allPath;
    
    void dfs(vector<vector<int>>& graph, int start, int end, vector<int> path){
        path.push_back(start);
        
        if(start == end){
            allPath.push_back(path);
            return;
        }
        for(auto &st : graph[start]){
            dfs(graph, st, end, path);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start = 0, end = graph.size() - 1;
        dfs(graph, start, end, vector<int>());
        return allPath;
    }
};