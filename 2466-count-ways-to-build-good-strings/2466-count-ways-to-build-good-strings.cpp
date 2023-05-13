const int kMod = 1e9 + 7;
const int kMax = 1e5 + 1;

class Solution {
private:
    vector<int> cache_;
public:
    int dfs(int end, int zero, int one) {
        if (end <= 0) {
            return 1;
        }
        if (cache_[end] != -1) {
            return cache_[end];
        }
        int count = 0;
        if (end >= one) {
            count = (count + dfs(end - one, zero, one)) % kMod;
        }
        if (end >= zero) {
            count = (count + dfs(end - zero, zero, one)) % kMod;
        }
        return cache_[end] = count;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        cache_.resize(high + 1, -1);
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans = (ans + dfs(i, zero, one)) % kMod;
        }
        return ans;
    }
};