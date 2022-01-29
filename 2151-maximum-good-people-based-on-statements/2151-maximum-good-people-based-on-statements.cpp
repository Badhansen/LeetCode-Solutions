class Solution {
private:
    int n;
    int ans;
public:
    bool valid(vector<vector<int>>& statements, vector<int>& res){
        for(int i = 0; i < n; i++){
            if(res[i] == 1){
                for(int j = 0; j < n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != res[j])
                        return false;
                }
            }
        }
        return true;
    }
    void dfs(int pos, int count, vector<vector<int>>& statements, vector<int>& res){
        if(pos == n){
            if(valid(statements, res))
                ans = max(ans, count);
            return;
        }
        res.push_back(0);
        dfs(pos + 1, count, statements, res);
        res.back() = 1;
        dfs(pos + 1, count + 1, statements, res);
        res.pop_back();
        
    }
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        vector<int> res;
        dfs(0, 0, statements, res);
        return ans;
    }
};