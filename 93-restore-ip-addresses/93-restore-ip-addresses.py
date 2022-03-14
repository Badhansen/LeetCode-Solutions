class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        
        
        def is_valid(s):
            if s is None:
                return False
            if len(s) == 1:
                return True
            if int(s[0]) == 0:
                return False
            return 0 <= int(s) <= 255
        
        
        def dfs(pos, part, path, s, res):
            if part == 0 and pos == len(s):
                res.append(path[1 :])
                return
            if part == 0:
                return
            for i in range(pos, len(s)):
                if is_valid(s[pos : i + 1]):
                    dfs(i + 1, part - 1, path + '.' + s[pos : i + 1], s, res)
                else:
                    break
                  
                
        dfs(0, 4, '', s, res)
        
        return res
    