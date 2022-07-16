class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int result = 0;
        for (int i = 0; i < (1 << n); i++) {
            int mask = 0, size = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    size += arr[j].size();
                    for (int index = 0; index < arr[j].size(); index++) {
                        mask |= (1 << (arr[j][index] - 'a'));
                    }
                }
            }
            if (__builtin_popcount(mask) == size) {
                result = max(result, size);
            }
        }
        return result;
    }
};