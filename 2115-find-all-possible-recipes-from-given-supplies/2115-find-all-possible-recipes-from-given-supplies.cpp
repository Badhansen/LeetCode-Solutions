//@Author: KING-SEN
// 1 last try

class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;
    unordered_map<string, bool> visited;
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> answer;
        queue<string> que;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                graph[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        for(int i = 0; i < supplies.size(); i++){
            que.push(supplies[i]);
            visited[supplies[i]] = true;
        }
        while(!que.empty()){
            string src = que.front();
            que.pop();
            for(auto dest : graph[src]){
                indegree[dest]--;
                if(indegree[dest] == 0){
                    visited[dest] = true;
                    answer.push_back(dest);
                    que.push(dest);
                }
            }
        }
        return answer;
    }
};

// Time: O(V + E), V = number of repices, E = number of ingredients
// Space: O(V)