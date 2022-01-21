class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, int j, string &a, string &b){
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        if(a[i] != b[j]){
            int insert = solve(i, j + 1, a, b);
            int remove = solve(i + 1, j, a, b);
            int replace = solve(i + 1, j + 1, a, b);
            ret = min({insert, remove, replace}) + 1;
        }
        else ret = solve(i + 1, j + 1, a, b);
        return ret;
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        dp.resize(len1 + 1, vector<int> (len2 + 1, -1));
        return solve(0, 0, word1, word2);
    }
};