const int mod = 1000000007;

class Solution {
private:
    vector<long> dp;
    vector<long> memo;
public:
    long p(int n){
        if(n == 2)
            return 1ll;
        if(memo[n] != -1)
            return memo[n];
        return memo[n] = (p(n - 1) + f(n - 2)) % mod; 
    }
    long f(int n){
        if(n == 1 || n == 2)
            return n;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % mod;
    }
    int numTilings(int n) {
        memo.resize(n + 1, -1);
        dp.resize(n + 1, -1);
        return (int)f(n);
    }
};