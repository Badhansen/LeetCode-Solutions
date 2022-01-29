class Solution {
public:
    void solve(int start, int n, int k, vector<int> path, vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++){
            path.push_back(i);
            solve(i + 1, n, k - 1, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        solve(1, n, k, {}, ans);
        return ans;
    }
};