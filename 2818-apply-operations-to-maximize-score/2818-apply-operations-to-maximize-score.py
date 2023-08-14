primes = []
        
def seive():
    max_limit = 10 ** 5 + 5
    prime = [True for i in range(max_limit + 1)]
    p = 2
    while (p * p <= max_limit):
        if (prime[p] == True):
            for i in range(p * p, max_limit + 1, p):
                prime[i] = False
        p += 1
    for p in range(2, max_limit + 1):
        if prime[p]:
            primes.append(p)

seive()

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        def score(num):
            idx, n = 0, len(primes)
            cnt = 0
            while idx < n and primes[idx] * primes[idx] <= num:
                if num % primes[idx] == 0:
                    cnt += 1
                while num % primes[idx] == 0:
                    num /= primes[idx]
                idx += 1
            if num > 1:
                cnt += 1
            return cnt
        
        prime_score = dict([(x, score(x)) for x in nums])
        prime_score[float('inf')] = float('inf')
        
        nums.insert(0, float('inf'))
        nums.append(float('inf'))
        stack = []
        res = []
        answer, mod = 1, 10 ** 9 + 7
        # Calculate the range (l, r) where ith element is the largest
        for i in range(len(nums)):
            if not stack or prime_score[nums[stack[-1]]] > prime_score[nums[i]]:
                stack.append(i)
            else:
                while len(stack) > 1 and prime_score[nums[stack[-1]]] < prime_score[nums[i]]:
                    m = stack.pop()
                    l, r = stack[-1] + 1, i - 1
                    res.append([nums[m], [m, l, r]])
                stack.append(i)
        res.sort(reverse=True)
        idx = 0
        while k > 0:
            val = res[idx][0]
            m = res[idx][1][0]
            l = res[idx][1][1]
            r = res[idx][1][2]
            n = (m - l + 1) * (r - m + 1)
            power = min(k, n)
            answer = (answer * pow(val, power, mod)) % mod
            k -= n
            idx += 1
        return answer

