class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        n = len(data)
        left = right = 0
        curr = maxx = 0
        while right < n:
            curr += data[right]
            right += 1
            while right - left > ones:
                curr -= data[left]
                left += 1
            maxx = max(maxx, curr)
        return ones - maxx

        