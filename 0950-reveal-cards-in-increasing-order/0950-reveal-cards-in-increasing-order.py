class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        inc, res = [], [0] * len(deck)
        deck.sort()
        q = deque()
        for i in range(len(deck)):
            q.append(i)
        while q:
            inc.append(q.popleft())
            if q:
                q.append(q.popleft())
        for i in range(len(deck)):
            res[inc[i]] = deck[i]
        return res