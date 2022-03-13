class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int sid, int tid, string& s, string& t){
        if(sid == s.size()){
            return tid == t.size();
        }
        if(tid == t.size()){
            return 1;
        }
        int &ret = dp[sid][tid];
        if(ret != -1){
            return ret;
        }
        int include = 0, exclude = 0;
        if(s[sid] == t[tid]){
            include = solve(sid + 1, tid + 1, s, t);
        }
        exclude = solve(sid + 1, tid, s, t);
        return ret = include + exclude;
    }
    
    int numDistinct(string s, string t) {
        dp.resize(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t);
    }
};