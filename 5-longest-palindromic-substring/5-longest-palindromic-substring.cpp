class Solution {
private:
    int dp[1001][1001];
public:
    int solve(int x, int y, string& s){
        if(x >= y){
            return 1;
        }
        int &ret = dp[x][y];
        if(ret != -1){
            return ret;
        }
        if(s[x] == s[y]){
            ret = solve(x + 1, y - 1, s);
        }
        else{
            ret = 0;
        }
        return ret;
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof dp); 
        int start, end, maxx = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = s.size() - 1; j >= 0; j--){
                if(solve(i, j, s) && j - i + 1 > maxx){
                    start = i, end = j, maxx = j - i + 1;
                }
            }
        }
        return s.substr(start, maxx);
    }
};