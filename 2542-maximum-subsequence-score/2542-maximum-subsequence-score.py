class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        res = float("-inf")
        pairs = [(nums1[i], nums2[i]) for i in range(len(nums1))] # (nums1, nums2)
        pairs.sort(key=lambda p:p[1], reverse=True)
        minHeap = [] # minimum from the subsequence
        total = 0
        for i in range(len(nums1)):
            total += pairs[i][0]
            heapq.heappush(minHeap, pairs[i][0])
            
            if len(minHeap) > k:
                total -= heapq.heappop(minHeap)
            if len(minHeap) == k:
                res = max(res, total * pairs[i][1])
        return res