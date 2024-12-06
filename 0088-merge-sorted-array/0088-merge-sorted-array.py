class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end = m + n - 1
        m -= 1
        n -= 1
        while n >= 0:
            if m >= 0 and nums1[m] > nums2[n]:
                nums1[end] = nums1[m]
                m -= 1
            else:
                nums1[end] = nums2[n]
                n -= 1
            end -= 1
            



