// Recursive memoization solution

class Solution {
private:
    vector<int> dp;
public:
    int ways(int pos, string &s) {
        if (pos >= s.size()) {
            return 1;
        }
        int &result = dp[pos];
        if (result != -1) {
            return result;
        }
        result = 0;
        int take = s[pos] - '0';
        if (take) {
            result = ways(pos + 1, s);
        }
        if (pos + 1 < s.size()) {
            take = stoi(s.substr(pos, 2));
            if (take >= 10 && take <= 26) {
                result += ways(pos + 2, s);
            }
        }
        return result;
    }
    int numDecodings(string s) {
        dp.clear();
        dp.resize(s.size(), -1);
        return ways(0, s);
    }
};

// Time: O(N)
// Space: O(N)

// // Iterative solution

// class Solution {
// public:
//     int numDecodings(string s) {
//         int len = s.size();
//         vector<int> dp(len + 1);
//         dp[0] = 1;
//         dp[1] = s[0] == '0' ?  0 : 1;
//         for (int i = 2; i <= len; i++) {
//             if (s[i - 1] != '0') {
//                 dp[i] += dp[i - 1];
//             }
//             int number = stoi(s.substr(i - 2, 2));
//             if (number >= 10 && number <= 26) {
//                 dp[i] += dp[i - 2];
//             }
//         }
//         return dp[len];
//     }
// };

// // Time: O(N)
// // Space: O(N)