class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        def make_mask(skills):
            mask = 0
            for s in skills:
                mask |= (1 << req_skills.index(s))
            return mask
        
        smask = [make_mask(p) for p in people]
        n = len(people)
        m = len(req_skills)
        memo = defaultdict(lambda: -1)
        
        def solve(i, mask):
            if mask == 0:
                return 0
            if i < 0:
                return (1 << n) - 1
            if (i, mask) in memo:
                return memo[(i, mask)]
            req_mask = mask & (~smask[i])
            taken = (1 << n) - 1
            if req_mask != mask:
                taken = solve(i - 1, req_mask) | (1 << i)
            not_taken = solve(i - 1, mask)
            if taken.bit_count() <= not_taken.bit_count():
                memo[(i, mask)] = taken
            else:
                memo[i, mask] = not_taken
            return memo[(i, mask)]
        
        ans = solve(n - 1, (1 << m) - 1)
        res = [i for i in range(n) if ans & (1 << i)]
        return res
