class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod = 10 ** 9 + 7
        dp = {}
        
        def count(curr_goal, old_songs):
            if curr_goal == 0 and old_songs == n:
                return 1
            if curr_goal == 0 or old_songs > n:
                return 0
            if (curr_goal, old_songs) in dp:
                return dp[(curr_goal, old_songs)]
            res = ((n - old_songs) * count(curr_goal - 1, old_songs + 1)) % mod
            if old_songs > k:
                res += ((old_songs - k) * count(curr_goal - 1, old_songs)) % mod
            dp[(curr_goal, old_songs)] = res % mod
            return res % mod
            
        
        return count(goal, 0)