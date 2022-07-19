const int kLength = 20;
const int kSum = 2005;

class Solution {
public:
    int cache[kLength][kSum];
    int target, total;
public:
    int TotalWays(int index, int sum, vector<int>& nums) {
        if (index == nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        if(cache[index][sum + total] != -1) return cache[index][sum + total];
        int ways1 = TotalWays(index + 1, sum + nums[index], nums);
        int ways2 = TotalWays(index + 1, sum - nums[index], nums);
        return cache[index][sum + total] = ways1 + ways2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0;
        for (auto n : nums) total += n;
        this->target = target;
        memset(cache, -1, sizeof cache);
        return TotalWays(0, 0, nums);
    }
};