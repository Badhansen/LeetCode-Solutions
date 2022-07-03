class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        long ans = 0;
        for(int d = 0; d < n; d++){
            for(int i = d + delay; i < d + forget && i < n; i++){
                dp[i] = (dp[d] + dp[i]) % mod;
            }
        }
        for(int i = n - forget; i < n; i++){
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};

// 1 2 3 4
// 1 0 0 0
// 0 1 1 0  A
//     1 1  B
//       1  B

// 1 2 3 4 5 6
// 1 0 0 0 0 0
//     1 1 0 0
// 0 0 0 0 1 1
// 0 0 0 0 0 0