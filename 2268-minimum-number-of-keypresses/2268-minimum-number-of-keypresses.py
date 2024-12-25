class Solution:
    def minimumKeypresses(self, s: str) -> int:
        counter = Counter(s)
        values = sorted(counter.items(), key=lambda x:x[1], reverse=True)
        orders = [0] * 26
        pressed = keys = 1
        res = 0
        for key, val in values:
            x = ord(key) - 97
            if not orders[x]:
                orders[x] = pressed
                keys += 1
                if keys == 10:
                    keys = 1
                    pressed += 1
            res += orders[x] * val
        return res
            
        
                