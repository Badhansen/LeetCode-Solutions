class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> visited;
    unordered_map<string, int> present;
public:
    bool dfs(string src){
        if(graph[src].size() == 0) return present.count(src);
        visited[src] = 1;
        for(auto dest : graph[src]){
            if(visited[dest] == 1) return false;
            if(visited[dest] == 0 && !dfs(dest)){
                return false;
            }
        }
        visited[src] = 2;
        return true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        for(auto s : supplies) present[s] = 1;
        for(int i = 0; i < n; i++){
            for(auto &node : ingredients[i]){
                graph[recipes[i]].push_back(node);
            }
        }
        vector<string> answer;
        for(auto &r : recipes){
            if(visited[r] == 2) answer.push_back(r);
            else if(dfs(r)) answer.push_back(r);
            
        }
        return answer;
    }
};