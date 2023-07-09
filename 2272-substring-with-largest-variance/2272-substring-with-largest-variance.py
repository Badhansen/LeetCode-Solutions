class Solution:
    def largestVariance(self, s: str) -> int:
        max_variance = 0
        
        pairs = [(l1, l2) for l1 in set(s) for l2 in set(s) if l1 != l2]
        
        for runs in range(2):
            for pair in pairs:
                count1 = count2 = 0
                for char in s: 
                    if char not in pair:
                        continue
                    elif char == pair[0]:
                        count1 += 1
                    elif char == pair[1]:
                        count2 += 1
                    
                    if count1 < count2:
                        count1 = count2 = 0
                    if count1 and count2:
                        max_variance = max(max_variance, count1 - count2)
            s = s[::-1]
        return max_variance
                        