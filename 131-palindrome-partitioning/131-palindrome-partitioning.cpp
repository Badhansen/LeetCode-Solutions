class Solution {
public:
    void dfs(string& s, int start, vector<string>& res, vector<vector<string>>& ans, vector<vector<bool>>& dp){
        if(start >= s.size()){
            ans.emplace_back(res);
            return;
        }
        for(int end = start; end < s.size(); end++){
            if(s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])){
                dp[start][end] = true;
                res.emplace_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, res, ans, dp);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<string> res;
        vector<vector<string>> ans;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        dfs(s, 0, res, ans, dp);
        return ans;
    }
};