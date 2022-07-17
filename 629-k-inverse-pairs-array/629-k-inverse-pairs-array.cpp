const int kMod = 1e9 + 7;
const int kMaxN = 1005;
const int kMaxK = 1005;

class Solution {
private:
    int cache[kMaxN][kMaxK] = {1};
public:
    int kInversePairs(int n, int k) {
        for (int N = 1; N <= n; ++N) {
            for (int K = 0; K <= k; ++K) {
                for (int i = 0; i <= min(K, N - 1); ++i) { 
                    cache[N][K] = (cache[N][K] + cache[N - 1][K - i]) % kMod;
                }
            }
        }
        return cache[n][k];
	}
};

/*
    Time: O(n * k * k)
    Memory: O(n * k)
*/