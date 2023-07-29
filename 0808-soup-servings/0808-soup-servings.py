class Solution:
    def __init__(self):
        self._option1 = [100, 75, 50, 25]
        self._option2 = [0, 25, 50, 75]
        
    def func(self, a, b, dp):
        if a == 0 and b == 0:
            return 0.5
        if a == 0:
            return 1.0
        if b == 0:
            return 0.0
        if dp[a][b] != -1:
            return dp[a][b]
        ans = 0
        for k in range(4):
            rem1 = a - self._option1[k]
            rem2 = b - self._option2[k]
            ans += 0.25 * self.func(max(0, rem1), max(0, rem2), dp)
        dp[a][b] = ans
        return ans
    
    def soupServings(self, n: int) -> float:
        if n >= 4800:
            return 1.0
        dp = [[-1] * (n + 1) for _ in range(n + 1)]
        return self.func(n, n, dp)