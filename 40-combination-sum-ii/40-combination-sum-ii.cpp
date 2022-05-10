class Solution {
public:
    vector<vector<int>> answer;
    void dfs(int pos, vector<int>& candidates, int target, vector<int>& path){
        if(target == 0){
            answer.push_back(path);
            return;
        }
        if(target < 0 || pos >= candidates.size()){
            return;
        }
        for(int i = pos; i < candidates.size(); i++){
            if(i > pos && candidates[i] == candidates[i- 1]){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i], path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, path);
        return answer;
    }
};