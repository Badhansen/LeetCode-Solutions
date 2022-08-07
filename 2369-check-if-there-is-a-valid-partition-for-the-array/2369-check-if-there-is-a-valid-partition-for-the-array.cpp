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