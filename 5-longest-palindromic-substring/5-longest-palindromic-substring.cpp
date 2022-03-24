// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int dp[1001][1001];
    int solve(int x, int y, string& S)
    {  
        if(x > y) return 0;
        int &ret = dp[x][y];
        if(ret != -1){ 
            return ret;
        }
        if(S[x] == S[y]){
            int val = solve(x + 1, y - 1, S);
            if(val >= (y - 1) - (x + 1) + 1){
                ret = 2 - (x == y) + val;
            }
        }
        ret = max({ret, solve(x + 1, y, S), solve(x, y - 1, S)});
        return ret;
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof dp);
        int ret = solve(0, s.size() - 1, s);
        int startIndex;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(ret == dp[i][j]){
                    startIndex = j - ret + 1;
                    break;
                }
            }
        }
        return s.substr(startIndex, ret);
    }
};

// Time Complexity: O(N^2), where N is the lenght of the string
// Space complexity: O(N^2), we used 2d vector array to store the intermediate result
