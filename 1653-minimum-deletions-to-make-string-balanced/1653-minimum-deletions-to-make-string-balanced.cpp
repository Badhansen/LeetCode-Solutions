//@Author: KING-SEN

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int pos, int bflag, string& s){
        if(pos >= s.size()){
            return 0;
        }
        
        int &ret = dp[pos][bflag];
        if(ret != -1){
            return ret;
        }
        ret = INT_MAX;
        if(bflag){
            ret = (s[pos] == 'a') + solve(pos + 1, bflag, s);   
        }
        else{
            if(s[pos] == 'b'){
                ret = solve(pos + 1, 1, s);
            }
            ret = min(ret, (s[pos] == 'b') + solve(pos + 1, 0, s));
        }
        return ret;
    }
    int minimumDeletions(string s) {
        int len = s.size();
        dp.resize(len + 1, vector<int> (2, -1));
        return solve(0, 0, s);
    }
};