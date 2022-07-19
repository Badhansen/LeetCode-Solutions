class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        cache[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> cache2;
            for (auto [key, value] : cache) {
                int key1 = key + num;
                cache2[key1] += cache[key];
                int key2 = key - num; 
                cache2[key2] += cache[key];
            }
            cache = cache2;
        }
        return cache[target];
    }
};
/*
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
*/
/*
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
*/