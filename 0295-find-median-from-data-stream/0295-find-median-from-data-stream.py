class MedianFinder:

    def __init__(self):
        self.left = []    # max heap (invert values to simulate max heap)
        self.right = []   # min heap

    def addNum(self, num: int) -> None:
        # Push negative of num to left (max heap)
        heapq.heappush(self.left, -1 * num)
        
        # Push smallest of left (max heap) to right (min heap)
        heapq.heappush(self.right, -1 * heapq.heappop(self.left))
        
        # Balance heaps
        if len(self.left) < len(self.right):
            heapq.heappush(self.left, -1 * heapq.heappop(self.right))

    def findMedian(self) -> float:
        if len(self.left) > len(self.right):
            return -1 * self.left[0]
        else:
            return (-1 * self.left[0] + self.right[0]) / 2.0
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()