class Solution {
private:
    long long count[65];
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long result = 0;
        set<int> val(nums.begin(), nums.end());
        for (auto n : val) {
            count[__builtin_popcount(n)]++;
        }
        for (int i = 0; i <= 32; i++) {
            for (int j = 0; j <= 32; j++) {
                if (i + j >= k) {
                    result += count[i] * count[j];
                }
            }
        }
        return result;
    }
};