class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n = len(nums1)
        score = [(nums1[i], nums2[i]) for i in range(n)]
        score.sort(key=lambda x : x[1], reverse=True)
        heap = []
        total, res = 0, 0
        for i in range(n):
            total += score[i][0]
            heappush(heap, score[i][0])
            if len(heap) >= k:
                res = max(res, total * score[i][1])
                total -= heappop(heap)
        return res