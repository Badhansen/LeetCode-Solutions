# KING-SEN

class Solution:
    def visibleMountains(self, peaks: List[List[int]]) -> int:
        dist = [[x - y, x + y] for x, y in peaks]
        dist.sort(key=lambda d:(d[0], -d[1]))
        i, invisible = 0, 0
        #  Count number of intervals that are entirely inside other
        while i < len(dist):
            end = dist[i][1]
            j = i + 1
            if j < len(dist) and dist[i] == dist[j]:
                invisible += 1
            while j < len(dist):
                y = dist[j][1]
                if y > end:
                    break
                invisible += 1
                j += 1
            i = j
        return len(dist) - invisible