class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count, ans = 0, 0
        for n in nums:
            if n == 1:
                count += 1
            else:
                count = 0;
            ans = max(ans, count)
        return ans