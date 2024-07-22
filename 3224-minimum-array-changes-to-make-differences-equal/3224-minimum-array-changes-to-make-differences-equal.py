class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq = [0] * (k + 1)
        maxReach = [0] * (k + 1)
        for i in range(n // 2):
            a, b = nums[i], nums[n - i - 1]
            freq[abs(a - b)] += 1
            threshold = max(max(a, b), k - min(a, b))
            maxReach[threshold] += 1 #  Max difference that can be reached by current pair
        for i in range(k - 1, -1, -1):
            maxReach[i] += maxReach[i + 1] 
        res = float("inf")
        for i in range(k + 1):
            oneStep = maxReach[i] - freq[i]
            twoSteps = n // 2 - oneStep - freq[i]
            res = min(res, oneStep + twoSteps * 2)
        return res