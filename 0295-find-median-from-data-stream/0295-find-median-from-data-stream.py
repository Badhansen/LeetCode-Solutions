class MedianFinder:
    def __init__(self):
        self.left = [] # Max heap
        self.right = [] # Min heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.left, -1 * num)
        n = -1 * heapq.heappop(self.left)
        heapq.heappush(self.right, n)
        if len(self.right) > len(self.left):
            n = heapq.heappop(self.right)
            heapq.heappush(self.left, -1 * n)
        

    def findMedian(self) -> float:
        if (len(self.left) + len(self.right)) % 2 == 0:
            return (-1 * self.left[0] + self.right[0]) / 2.0
        return -1 * self.left[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()