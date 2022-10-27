// @Author: KING-SEN

const int kMaxOperations = 7;
const int kMaxN = 14;
const int kTotal = 1 << kMaxN;

class Solution {
private:
    int _cache[kMaxOperations + 1][kTotal + 1];
public:
    int solve(int operations, int mask, vector<int>& nums) {
        if (operations == nums.size() / 2) {
            return 0;
        }
        int &result = _cache[operations][mask];
        if (result != -1) {
            return result;
        }
        result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (!(mask & (1 << i)) && !(mask & (1 << j))) {
                    int score = __gcd(nums[i], nums[j]) * (operations + 1);
                    result = max(result, score + solve(operations + 1, mask | (1 << i) | (1 << j), nums));
                }
            }
        }
        return result;
    }
    int maxScore(vector<int>& nums) {
        memset(_cache, -1, sizeof _cache);
        int answer = solve(0, 0, nums);
        return answer;
    }
};