const int kMod = 1e9 + 7;
const int kLen = 25;
const int kValue = 405;

class Solution {
public:
    int dp[2][2][kLen][kValue];
    int limit, min_sum, max_sum;
    int solve(int pos, bool isSmall, bool isStart, int sum, string &num) {
        if (pos == limit) {
            return sum >= min_sum && sum <= max_sum;
        }
        int &ret = dp[isSmall][isStart][pos][sum];
        if (ret != -1) {
            return ret;
        }
        int last = isSmall ? 9 : num[pos] - '0';
        ret = 0;
        if (!isStart) {
            for (int i = 0; i <= last; i++) {
                ret = (ret + solve(pos + 1, isSmall | (i < num[pos] - '0'), false, i + sum, num) % kMod) % kMod;
            }
        } else {
            for (int i = 1; i <= last; i++) {
                ret = (ret + solve(pos + 1, isSmall | (i < num[pos] - '0'), false, i + sum, num) % kMod) % kMod;
            }
            ret = (ret + solve(pos + 1, true, true, 0, num) % kMod) % kMod;
        }
        return ret;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        limit = num2.size();
        this->min_sum = min_sum, this->max_sum = max_sum;
        memset(dp, -1, sizeof dp);
        int right = solve(0, 0, 1, 0, num2) % kMod;
        limit = num1.size();
        memset(dp, -1, sizeof dp);
        int left = solve(0, 0, 1, 0, num1) % kMod;
        
        int ans = (right - left + kMod) % kMod;
        int sum = 0;
        for (auto n : num1) {
            sum += (n - '0');
        }
        if (sum >= min_sum && sum <= max_sum) {
            ans = (ans + 1) % kMod;
        }
        return ans;
    }
};