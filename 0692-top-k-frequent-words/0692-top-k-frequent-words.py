class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = Counter(words)
        sorted_list = sorted(counter.items(), key=lambda x:(-x[1], x[0]))
        return [key for key, count in sorted_list][:k]