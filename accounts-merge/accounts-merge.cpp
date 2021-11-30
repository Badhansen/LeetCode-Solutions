class Solution {
private:
    unordered_map<string, bool> visited;
    unordered_map<string, vector<string>> graph;
public:
    void dfs(vector<string>& account, string email){
        visited[email] = true;
        account.push_back(email);
        
        for(string& node : graph[email]){
            if(!visited.count(node)){
                dfs(account, node);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        string firstEmail, email, name;
        
        for(auto &account : accounts){
            int len = account.size();
            string firstEmail = account[1], email;
            
            for(int i = 2; i < len; i++){
                email = account[i];
                graph[firstEmail].push_back(email);
                graph[email].push_back(firstEmail);
            }
        }
        vector<vector<string>> result;
            
        for(auto &account : accounts){
            name = account[0];
            firstEmail = account[1];
            
            if(!visited.count(firstEmail)){
                vector<string> account;
                account.push_back(name);
                
                dfs(account, firstEmail);
                
                sort(account.begin() + 1, account.end());
                result.push_back(account);
            }
        }
        
        return result;
    }
};