class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        count, prev, answer = 0, -1, 0 
        for n in nums:
            if prev < n:
                count += 1
                prev = n
            else:
                answer = max(answer, count)
                count, prev = 1, n
        return max(count, answer)