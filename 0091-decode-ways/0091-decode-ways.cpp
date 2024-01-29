// Recursive memoization solution

class Solution {
private:
    vector<int> dp;
public:
    int ways(int pos, string &s) {
        if (pos >= s.size()) {
            return 1;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int take1 = 0, take2 = 0;
        if (s[pos] != '0') {
            take1 = ways(pos + 1, s);
            if (pos + 1 < s.size() ) {
                int number = stoi(s.substr(pos, 2));
                if (number >= 10 && number <= 26) {
                    take2 = ways(pos + 2, s);
                }
            }
        }
        return dp[pos] = take1 + take2;
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