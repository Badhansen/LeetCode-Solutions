const int kMod = 1e9 + 7;
const int kMaxN = 1005;
const int kMaxK = 1005;

class Solution {
private:
    int dp[kMaxN][kMaxK] = {1};
public:
    int kInversePairs(int n, int k) {
        for (int N = 1; N <= n; ++N) {
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % kMod;
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % kMod;
            }
        }
        return dp[n][k];
	}
};

/*
    Time: O(n * k * k)
    Memory: O(n * k)
*/