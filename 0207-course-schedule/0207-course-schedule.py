class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(lambda: list())
        indegree = [0] * numCourses
        
        for c in prerequisites:
            indegree[c[0]] += 1
            graph[c[1]].append(c[0])
        
        visited = set()
        course = list()
        
        for node in range(numCourses):
            if indegree[node] == 0:
                course.append(node)
        
        done = 0
        
        while course:
            src = course.pop(0)
            done += 1
            for dest in graph[src]:
                indegree[dest] -= 1
                if indegree[dest] == 0:
                    course.append(dest)
        
        return True if done == numCourses else False