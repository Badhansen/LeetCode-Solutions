class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = list()
        for ast in asteroids:
            blows = False
            while res and ast < 0 and res[-1] > 0 and not blows:
                if abs(ast) < res[-1]:
                    blows = True
                else:
                    if abs(ast) == res[-1]:
                        blows = True
                        res.pop()
                    else:
                        res.pop()
            if not blows:
                res.append(ast)
        return res