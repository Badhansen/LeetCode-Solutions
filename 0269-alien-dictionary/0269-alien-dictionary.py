class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = defaultdict(list)
        freq = defaultdict(int)
        for word in words:
            for c in word:
                # unique char freq will be one, 0 means the char is absent in alien language
                freq[c] = 1 
        for i in range(len(words) - 1):
            a, b = words[i], words[i + 1]
            if len(a) > len(b) and a[:len(b)] == b:
                return ""
            for j in range(min(len(a), len(b))):
                if a[j] != b[j]:
                    graph[a[j]].append(b[j])
                    freq[b[j]] += 1
                    break
        unique = sum(1 for val in freq.values() if val > 0)
        que = deque([key for key, val in freq.items() if val == 1])
        res = []
        while que:
            n = que.popleft()
            res.append(n)
            for c in graph[n]:
                freq[c] -= 1
                if freq[c] == 1:
                    que.append(c)
        return ''.join(res) if len(res) == unique else ""