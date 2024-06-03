class SegmentTree:
    def __init__(self, n):
        self.len = 1
        while self.len < n:
            self.len *= 2
        self.tree = [[[0, 0], [0, 0]] for _ in range(0, 2 * self.len)]
    def glue(self, l, r):        
        '''
               [2, 1, 2, 4]  [8, 3, 6, 5]
          x00 = i        k   1-k        j
          x01 = 0        k   1-k        1
        '''
        res = [[0, 0], [0, 0]]
        for i in [0, 1]:
            for j in [0, 1]:
                for k in [0, 1]:
                    res[i][j] = max(res[i][j], l[i][k] + r[1 - k][j])
        return res
        
    def _build(self, v, n, x, lx, rx):
        if rx - lx == 1:
            if lx < n:
                self.tree[x] = [[0, 0], [0, v[lx]]]
            return
        m = (lx + rx) // 2
        self._build(v, n, 2 * x + 1, lx, m)
        self._build(v, n, 2 * x + 2, m, rx)
        self.tree[x] = self.glue(self.tree[2 * x + 1], self.tree[2 * x + 2])
    def build(self, v, n):
        self._build(v, n, 0, 0, self.len)
    
    def _set(self, i, v, x, lx, rx):
        if rx - lx == 1:
            self.tree[x] = [[0, 0], [0, v]]
            return
        m = (lx + rx) // 2
        if i < m:
            self._set(i, v, 2 * x + 1, lx, m)
        else:
            self._set(i, v, 2 * x + 2, m, rx)
        self.tree[x] = self.glue(self.tree[2 * x + 1], self.tree[2 * x + 2])
    
    def set(self, i, v):
        self._set(i, v, 0, 0, self.len)
        
    def _get(self, l, r, x, lx, rx):
        if lx >= r or l >= rx:
            return [[0, 0], [0, 0]]
        if lx >= l and rx <= r:
            return self.tree[x]
        m = (lx + rx) // 2
        left = self._get(l, r, 2 * x + 1, lx, m)
        right = self._get(l, r, 2 * x + 2, m, rx)
        return self.glue(left, right)
    
    def get(self, l, r):
        return self._get(l, r, 0, 0, self.len)
    
class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        st = SegmentTree(n)
        st.build(nums, n)
        ans, mod = 0, 10 ** 9 + 7
        for q in queries:
            st.set(q[0], q[1])
            res = st.get(0, n)
            ans += max(max(row) for row in res)
            ans %= mod
        return ans                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                