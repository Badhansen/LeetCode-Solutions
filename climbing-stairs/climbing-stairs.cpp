class Solution {
private:
    vector<int> dp;
public:
    int ways(int pos, int n){
        if(pos > n) return 0;
        if(pos == n) return 1;
        int& ret = dp[pos];
        if(ret != -1) 
            return ret;
        ret = ways(pos + 1, n) + ways(pos + 2, n);
        return ret;
    }
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return ways(0, n);
    }
};