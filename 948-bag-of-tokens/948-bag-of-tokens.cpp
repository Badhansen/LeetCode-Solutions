class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int score = 0, res = 0;
        while (left <= right) {
            while (left <= right && power - tokens[left] >= 0) {
                score++;
                power -= tokens[left++];
            }
            res = max(res, score);
            if (score) {
                power += tokens[right--];
                score--;
            } else break;
        }
        return res;
    }
};