class Solution {
public:
    const int mod = 1e9 + 7;
    int n;
    long long dp[100005][3][2];
    long long solve(int pos, int late, int abs){
        if(late > 2 || abs > 1){
            return 0ll;
        }
        if(pos == n){
            return 1ll;
        }
        long long &ret = dp[pos][late][abs];
        if(ret != -1){
            return ret;
        }
        ret = (solve(pos + 1, 0, abs) % mod + solve(pos + 1, late + 1, abs) % mod + 
            solve(pos + 1, 0, abs + 1) % mod) % mod;
        return ret;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        return solve(0, 0, 0);
    }
};

// Time: O(n * 3 * 2) ~ O(n)
// Space: O(n 8 3 * 2) ~ O(n)