// @Author: KING-SEN

class Solution {
private:
    vector<vector<int>> _cache;
    int _length;
public:
    int solve(int pos, int mask, vector<int>& nums1, vector<int>& nums2) {
        if (pos == _length) {
            return 0;
        }
        int &result = _cache[pos][mask];
        if (result != -1) {
            return result;
        }
        result = INT_MAX;
        for (int i = 0; i < _length; i++) {
            if ((mask & (1 << i)) == 0) {
                result = min(result, (nums1[pos] ^ nums2[i]) + solve(pos + 1, mask | (1 << i), nums1, nums2));
            }
        }
        return result;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        _length = nums1.size();
        int total = (1 << _length);
        _cache.resize(_length, vector<int> (total, -1));
        return solve(0, 0, nums1, nums2);
    }
};

// Space & Time Complexity: O(N * (2 ^ N))