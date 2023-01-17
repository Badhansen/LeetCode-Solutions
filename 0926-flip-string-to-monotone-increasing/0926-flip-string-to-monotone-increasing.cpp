class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.size();
        vector<int> dp(len + 1, 0);
        for(int i = 0; i < len; i++){
            dp[i + 1] = dp[i] + (s[i] == '1' ? 1 : 0);
        }
        int answer = INT_MAX;
        for(int i = 0; i <= len; i++){
            answer = min(answer, dp[i] + len - i - (dp[len] - dp[i]));
        }
        return answer;
    }
};