class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        dp = {}
        def func(left, right, p):
            if left > right:
                return 0
            if (left, right, p) in dp:
                return dp[(left, right, p)]
            s1type1, s1type2, s2type1, s2type2 = 0, 0, 0, 0
            if p:
                s1type1 = nums[left] + func(left + 1, right, not p)
                s1type2 = nums[right] + func(left, right - 1, not p)
                dp[(left, right, p)] = max(s1type1, s1type2)
            else:
                s2type1 = func(left + 1, right, not p) - nums[left]
                s2type2 = func(left, right - 1, not p) - nums[right]
                dp[(left, right, p)] = min(s2type1, s2type2)
            return dp[(left, right, p)]
        player1 = func(0, len(nums) - 1, 1)
        return player1 >= 0
            
            