class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        indegree = [0] * numCourses
        for u, v in prerequisites:
            graph[v].append(u)
            indegree[u] += 1
        sources = deque([i for i in range(numCourses) if indegree[i] == 0])
        res = []
        while sources:
            src = sources.popleft()
            res.append(src)
            for dest in graph[src]:
                indegree[dest] -= 1
                if indegree[dest] == 0:
                    sources.append(dest)
                
        return res if len(res) == numCourses else []