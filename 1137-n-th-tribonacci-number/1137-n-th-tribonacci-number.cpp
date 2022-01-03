class Solution {
public:
    int solve(int n, vector<int>& memo){
        if(n < 2) return n;
        else if(n == 2) return 1;
        else if(memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 3, memo) + solve(n - 2, memo) + solve(n - 1, memo);
    }
    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};