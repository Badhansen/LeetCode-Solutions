from sortedcontainers import SortedList

class SegmentTree:
    def __init__(self, n):
        self.len = 1
        while self.len < n:
            self.len *= 2
        self.tree = [0] * (2 * self.len)
        
    def _build(self, v, n, x, lx, rx):
        if rx - lx == 1:
            if lx < n:
                self.tree[x] = v[lx]
            return
        m = (lx + rx) // 2
        self._build(v, n, 2 * x + 1, lx, m)
        self._build(v, n, 2 * x + 2, m, rx)
        self.tree[x] = max(self.tree[2 * x + 1], self.tree[2 * x + 2])
    def build(self, v, n):
        self._build(v, n, 0, 0, self.len)
    
    def _set(self, i, v, x, lx, rx):
        if rx - lx == 1:
            self.tree[x] = v
            return
        m = (lx + rx) // 2
        if i < m:
            self._set(i, v, 2 * x + 1, lx, m)
        else:
            self._set(i, v, 2 * x + 2, m, rx)
        self.tree[x] = max(self.tree[2 * x + 1], self.tree[2 * x + 2])
    
    def set(self, i, v):
        self._set(i, v, 0, 0, self.len)
        
    def _get(self, l, r, x, lx, rx):
        if lx >= r or l >= rx:
            return float('-inf')
        if lx >= l and rx <= r:
            return self.tree[x]
        m = (lx + rx) // 2
        left = self._get(l, r, 2 * x + 1, lx, m)
        right = self._get(l, r, 2 * x + 2, m, rx)
        return max(left, right)
    
    def get(self, l, r):
        return self._get(l, r, 0, 0, self.len)


class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        n = 10 ** 5 + 5
        sl = SortedList()
        sl.add(0)
        sl.add(n)
        for q in queries:
            if q[0] == 1:
                x = q[1]
                sl.add(x)
        st = SegmentTree(n)
        for x, y in pairwise(sl):
            st.set(y, y - x)
        res = []
        for q in reversed(queries):
            if q[0] == 1:
                x = q[1]
                index = sl.index(x)
                before = sl[index - 1]
                after = sl[index + 1]
                sl.remove(x)
                st.set(after, after - before)
            else:
                _, x, sz = q
                index = sl.bisect_right(x)
                before = sl[index - 1]
                possible = st.get(0, before + 1) >= sz or (x - before) >= sz
                # print(st.get(0, before + 1), x - before, before)
                res.append(possible)
        res.reverse()
        return res
