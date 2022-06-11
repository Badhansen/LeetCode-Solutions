class Solution {
private:
    unordered_map<char, unordered_map<char, bool>> seen;
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto m : mappings){
            seen[m[0]][m[1]] = true;
        }
        int n = s.size(), m = sub.size();
        for(int i = 0; i <= n - m; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++, cnt++){
                if(s[i + j] == sub[j]) continue;
                else{
                    if(!seen[sub[j]].count(s[i + j])) break;
                }
            }
            //cout << cnt << endl;
            if(cnt == m) return true;
        }
        return false;
    }
};