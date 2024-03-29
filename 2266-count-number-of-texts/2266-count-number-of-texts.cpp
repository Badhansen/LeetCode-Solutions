const int kMod = 1e9 + 7;


class Solution {
private:
    vector<int> dp;
public:
    int ways(int pos, string& s) {
        if (pos <= 0) {
            return 1;
        }
        int &ret = dp[pos];
        if (ret != -1) {
            return ret;
        }
        int index = pos, limit = 0;
        while (index >= 0 && limit < 4 && s[pos] == s[index]) {
            index--, limit++;
        }
        if (limit == 4 && s[pos] != '7' && s[pos] != '9') limit = 3;
        ret = 0;
        for (int i = 1; i <= limit; i++) {
            ret = (ret + ways(pos - i, s)) % kMod;
        }
        return ret;
    }
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        dp.clear();
        dp.resize(n, -1);
        return ways(n - 1, pressedKeys);
    }
};

// Time: O(N * 4) ~ O(N)
// Space: O(N)

// class Solution {
// private:
//     int count[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
//     vector<int> dp;
// public:
//     int ways(int pos, string& s) {
//         if (pos == s.size()) {
//             return 1;
//         }
//         int &ret = dp[pos];
//         if (ret != -1) {
//             return ret;
//         }
//         ret = 0;
//         int limit = count[s[pos] - '0'], index = pos;
//         while (index < s.size() && s[pos] == s[index] && limit) {
//             index++, limit--;
//             ret = (ret + ways(index, s)) % kMod;
//         }
//         return ret;
//     }
//     int countTexts(string pressedKeys) {
//         int n = pressedKeys.size();
//         dp.clear();
//         dp.resize(n, -1);
//         return ways(0, pressedKeys);
//     }
// };

// // Time: O(N * 4) ~ O(N)
// // Space: O(N)