class Solution {
public:
    vector<int> dp;
    int Solve(int pos, string& s, const unordered_set<string>& seen) {
        if (pos >= s.size()) {
            return 0;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int result = 0;
        for (int l = 1; l <= s.size(); l++) {
            string word = s.substr(pos, l);
            int score = word.size();
            if (seen.count(word) > 0) {
                result = max(result, Solve(pos + word.size(), s, seen) + score);
            }
        }
        return dp[pos] = max(result, Solve(pos + 1, s, seen));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> seen(dictionary.begin(), dictionary.end());
        int n = s.size();
        dp.resize(n + 1, -1);
        int result = Solve(0, s, seen);
        return n - result;
    }
};