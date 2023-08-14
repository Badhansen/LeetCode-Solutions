isprime = [True] * 100001
primeFactors = [0] * 100001
for i in range(2, 100001):
    if isprime[i]:
        for j in range(i, 100001, i):
            isprime[j] = False
            primeFactors[j] += 1

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        p = [primeFactors[i] for i in nums]
        left = [-1] * n
        right = [n] * n
        
        # For each i, find the largest x < i s.t. p[x] >= p[i]
        stack = []
        for i in range(n):
            while stack and p[stack[-1]] < p[i]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)
            
        # For each i, find the smallest x > i s.t. p[x] > p[i]
        stack = []
        for i in range(n-1, -1, -1):
            while stack and p[stack[-1]] <= p[i]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)
            
        options = [(nums[i], (i - left[i]) * (right[i] - i)) for i in range(n)]
        res = 1
        for val, num in sorted(options, reverse = True):
            cur = min(num, k)
            k -= cur
            res = res * pow(val, cur, 1000000007) % 1000000007
            
        return res