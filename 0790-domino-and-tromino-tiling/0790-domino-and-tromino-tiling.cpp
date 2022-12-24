const int mod = 1000000007;

class Solution {
private:
    vector<long> dp;
public:
    long f(int n){
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (2 * f(n - 1) + f(n - 3)) % mod;
    }
    int numTilings(int n) {
        if(n == 1 || n == 2) 
            return n;
        
        dp.resize(n + 1, -1);
        
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        return (int)f(n);
    }
};