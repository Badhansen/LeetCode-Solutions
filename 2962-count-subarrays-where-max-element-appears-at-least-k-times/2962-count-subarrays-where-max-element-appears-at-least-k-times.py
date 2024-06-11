class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxElement = max(nums)
        ans, start, maxElementInWindow = 0, 0, 0
        for end in range(len(nums)):
            if nums[end] == maxElement:
                maxElementInWindow += 1
            while maxElementInWindow == k:
                if nums[start] == maxElement:
                    maxElementInWindow -= 1
                start += 1
            ans += start
        return ans
                