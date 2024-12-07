from sortedcontainers import SortedList

class StatisticsTracker:
    def __init__(self):
        self.sum = 0
        self.n = 0
        self.que = deque()
        self.sl = SortedList()
        self.pq = []
        self.freq = defaultdict(int)
        
    def addNumber(self, number: int) -> None:
        self.sum += number
        self.n += 1
        self.que.append(number)
        self.sl.add(number)
        self.freq[number] += 1
        heapq.heappush(self.pq, (-self.freq[number], number))

    def removeFirstAddedNumber(self) -> None:
        num = self.que.popleft()
        self.sum -= num
        self.n -= 1
        self.sl.discard(num)
        self.freq[num] -= 1
        heapq.heappush(self.pq, (-self.freq[num], num))

    def getMean(self) -> int:
        return self.sum // self.n

    def getMedian(self) -> int:
        if self.n > 0:
            return self.sl[self.n // 2]
        return 0

    def getMode(self) -> int:
        while self.pq and -self.pq[0][0] != self.freq[self.pq[0][1]]:
            heapq.heappop(self.pq)
        if self.pq:
            return self.pq[0][1]
        return 0


# Your StatisticsTracker object will be instantiated and called as such:
# obj = StatisticsTracker()
# obj.addNumber(number)
# obj.removeFirstAddedNumber()
# param_3 = obj.getMean()
# param_4 = obj.getMedian()
# param_5 = obj.getMode()