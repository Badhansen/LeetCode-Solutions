class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = Counter(students)
        res = 0
        for s in sandwiches:
            if count[s] == 0:
                break
            count[s] -= 1
            res += 1
        return len(students) - res