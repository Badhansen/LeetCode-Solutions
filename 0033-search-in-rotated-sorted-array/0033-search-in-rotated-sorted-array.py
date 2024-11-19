class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # l, r = 0, len(nums) - 1
        # while l < r:
        #     m = (l + r) // 2
        #     if nums[m] > nums[r]:
        #         l = m + 1
        #     else:
        #         r = m
        # pivot = l
        # def binarysearch(left: int, right: int) -> int:
        #     while left <= right:
        #         mid = (left + right) // 2
        #         if nums[mid] == target:
        #             return mid
        #         elif nums[mid] < target:
        #             left = mid + 1
        #         else:
        #             right = mid - 1
        #     return -1
        # res = binarysearch(0, pivot - 1)
        # if res != -1:
        #     return res
        # return binarysearch(pivot, len(nums) - 1)
        low, high = 0, len(nums) - 1

        while low <= high:
            mid = (low + high) // 2

            # Check if mid is the target
            if nums[mid] == target:
                return mid

            # Determine if the left half is sorted
            if nums[low] <= nums[mid]:
                # Target lies within the sorted left half
                if nums[low] <= target < nums[mid]:
                    high = mid - 1
                else:  # Target is in the right half
                    low = mid + 1
            else:
                # Right half is sorted
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:  # Target is in the left half
                    high = mid - 1

        # If we exit the loop, the target is not in the array
        return -1
