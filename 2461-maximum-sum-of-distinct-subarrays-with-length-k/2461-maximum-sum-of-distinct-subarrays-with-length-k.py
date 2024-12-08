class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res, total = 0, 0
        freq = defaultdict(int)
        for i in range(k):
            total += nums[i]
            freq[nums[i]] += 1
        if len(freq) == k:
            res = total
        left, right =0, k
        while right < n:
            total -= nums[left]
            if freq[nums[left]] == 1:
                del freq[nums[left]]
            else:
                freq[nums[left]] -= 1
            total += nums[right]
            freq[nums[right]] += 1
            left += 1
            right += 1
            if len(freq) == k:
                res = max(res, total)
        return res
            