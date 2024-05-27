class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        res = [0] * len(deck)
        deck.sort()
        q = deque()
        for i in range(len(deck)):
            q.append(i)
        for d in deck:
            res[q.popleft()] = d
            if q:
                q.append(q.popleft())
        return res