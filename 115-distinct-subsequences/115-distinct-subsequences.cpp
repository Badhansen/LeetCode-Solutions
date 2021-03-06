/*
Let's first define its state dp[i][j] to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. Then we have the following state equations:

General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.


"rabbbit"
"rabbit"

    r a b b b i t
  1 1 1 1 1 1 1 1 
r 0 1 1 1 1 1 1 1 
a 0 0 1 1 1 1 1 1 
b 0 0 0 1 2 3 3 3 
b 0 0 0 0 1 3 3 3 
i 0 0 0 0 0 0 3 3 
t 0 0 0 0 0 0 0 3 

Time: O(m*n)
Space: O(m*n)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<unsigned int> curr(m + 1, 0); 
        
        curr[0] = 1;
        for (int i = 1; i <= n; i++) {
            int prev = 1;
            for (int j = 1; j <= m; j++) {
                int temp = curr[j];
				if (t[j - 1] == s[i - 1]) {
                    curr[j] += prev;
                }
                prev = temp;
            }
        }
        return curr[m];
    }
};

/*
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1));
        
        for (int j = 0; j <= n; j++){
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
				if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
*/

/*
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
*/