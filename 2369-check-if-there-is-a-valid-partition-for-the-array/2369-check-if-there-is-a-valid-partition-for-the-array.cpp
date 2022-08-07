class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache = {true, false, nums[0] == nums[1], false};
        for (int i = 2; i < n; i++) {
            bool two = nums[i] == nums[i - 1];
            bool three = (two && nums[i - 1] == nums[i - 2]) ||
                        (nums[i] - 1 == nums[i - 1] && nums[i - 1] - 1 == nums[i - 2]);
            cache[(i + 1) % 4] = (two && cache[(i - 1) % 4]) || (three && cache[(i - 2) % 4]);
        }
        return cache[n % 4];
    }
};
/*
class Solution {
private:
    vector<int> cache;
    int n;
public:
    bool dfs(int pos, vector<int>& nums) {
        if (pos >= n - 1) {
            return pos == n;
        }
        if (cache[pos] != -1) return cache[pos];
        bool two, three = false;
        two = nums[pos] == nums[pos + 1];
        if (pos < nums.size() - 2) {
            three = (two && nums[pos + 1] == nums[pos + 2]) ||
                    (nums[pos] + 1 == nums[pos + 1] && nums[pos + 1] + 1 == nums[pos + 2]);
        }
        return cache[pos] = (two && dfs(pos + 2, nums)) || (three && dfs(pos + 3, nums));
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        cache.resize(n, -1);
        return dfs(0, nums);
    }
};
*/