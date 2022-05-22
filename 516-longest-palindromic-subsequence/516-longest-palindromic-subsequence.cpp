class Solution {
private:
    int dp[1001][1001];
public:
    int solve(int st, int ed, string& s){
        if(st > ed) return 0;
        if(st == ed) return 1;
        
        int &ret = dp[st][ed];
        
        if(ret != -1) return ret;
        
        if(s[st] == s[ed]){
            ret = solve(st + 1, ed - 1, s) + 2;
        }
        else{
            ret = max(solve(st + 1, ed, s), solve(st, ed - 1, s));
        }
        return ret;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, s.size() - 1, s);
    }
};