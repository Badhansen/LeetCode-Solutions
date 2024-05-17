# class Solution:
#     def pivot_index(self, nums: List[int]) -> int:
#         n = len(nums)
#         start, end = 0, n - 1
#         while start <= end:
#             mid = (start + end) // 2
#             if nums[mid] > nums[n - 1]:
#                 start = mid + 1
#             else:
#                 end = mid - 1
#         return start
    
#     def binary_search(self, start: int, end: int, target: int, nums: List[int]) -> int:
#         while start <= end:
#             mid = (start + end) // 2
#             if nums[mid] == target:
#                 return mid
#             elif nums[mid] > target:
#                 end = mid - 1
#             else:
#                 start = mid + 1
#         return -1
    
#     def search(self, nums: List[int], target: int) -> int:
#         n = len(nums)
#         index = self.pivot_index(nums)
        
#         if (answer := self.binary_search(0, index - 1, target, nums)) != -1:
#             return answer
#         return self.binary_search(index, n - 1, target, nums)

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid

            # left sorted portion
            if nums[l] <= nums[mid]:
                if target > nums[mid] or target < nums[l]:
                    l = mid + 1
                else:
                    r = mid - 1
            # right sorted portion
            else:
                if target < nums[mid] or target > nums[r]:
                    r = mid - 1
                else:
                    l = mid + 1
        return -1

        
            