class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        if n <= 2 or n == k:
            return 0
        partition = [0] * (n - 1)
        for i in range(n - 1):
            partition[i] = weights[i] + weights[i + 1]

        partition.sort()

        max_sum = sum(partition[n - k:]) #without weights[0]+weights[n-1]
        min_sum = sum(partition[:k - 1])
        return max_sum - min_sum