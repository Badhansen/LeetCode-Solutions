class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m = len(s1)
        n = len(s2)
        lenS3 = len(s3)
        
        if m == 0:
            return s2 == s3
        elif n == 0:
            return s1 == s3
        elif lenS3 == 0:
            return m + n == 0
        elif m + n != lenS3:
            return False
        
        t = [[False] * (n + 1) for i in range(m + 1)]
        t[0][0] = True
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Base conditions
                if s1[i-1] == s3[i-1]:
                    t[i][0] = t[i-1][0]
                
                if s2[j-1] == s3[j-1]:
                    t[0][j] = t[0][j-1]
                
                # Main logic - We're taking i + j - 1 in s3 because of 0-index
                if s1[i-1] == s3[i+j-1]:
                    t[i][j] = t[i-1][j]
                
                # We do an OR to cover the case that both s1 and s2 match.
                # This way we reduce an extra loop.
                if s2[j-1] == s3[i+j-1]:
                    t[i][j] = t[i][j] or t[i][j-1]
        
        return t[m][n]