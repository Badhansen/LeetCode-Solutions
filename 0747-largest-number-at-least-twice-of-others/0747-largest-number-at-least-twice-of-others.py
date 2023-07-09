class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_elements = [float('-inf')] * 2
        indexs = [0] * 2
        for i, n in enumerate(nums):
            if max_elements[0] < n:
                max_elements[1], max_elements[0] = max_elements[0], n
                indexs[1], indexs[0] = indexs[0], i
            elif max_elements[1] < n:
                max_elements[1] = n
                indexs[1] = i
        return indexs[0] if max_elements[1] * 2 <= max_elements[0] else -1
                