from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        buckets = [[] for i in range(len(nums) + 1)]
        for key, count in counts.items():
            buckets[count].append(key)
        results = [item for subList in buckets for item in subList]
        return results[-k:]
  
'''
Time complexity: O(N)
Space complexity: O(N)
'''

# from collections import Counter
# import heapq

# class Solution:
#     def topKFrequent(self, nums: List[int], k: int) -> List[int]:
#         counts = Counter(nums)
#         answer = list()
#         for key, value in counts.items():
#             heapq.heappush(answer, (value, key))
#             if len(answer) > k:
#                 heapq.heappop(answer)
        
#         return [item[1] for item in answer]

'''
Time complexity: O(N log K)
    Initializing the Counter object takes O(n) time, where n is the number of elements in the nums list.
    The main loop iterates over each key-value pair in the counts dictionary, which takes O(n) time.
    Within the loop, heappush and heappop operations each take O(log k) time, where k is the size of the heap (which is at most k).
    Therefore, the overall 
    time complexity of the code is O(n log k), where n is the number of elements in the nums list and k is the value of k.
Space complexity: O(N + K)
    The counts dictionary stores the counts of each element in nums, which requires O(n) space.
    The answer list stores at most k elements, which requires O(k) space.
    Therefore, the overall space complexity is O(n + k).
'''