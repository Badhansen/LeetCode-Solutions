class Solution:
    def removeStars(self, s: str) -> str:
        store = []
        for c in s:
            if c == '*' and store:
                store.pop()
            else:
                store.append(c)
        return ''.join(store)
        