class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(set)
        for u, v in prerequisites:
            graph[v].add(u)
        res = []
        visited = defaultdict(lambda: 0)
        def dfs(src):
            # Return false if the node is visited and viewed again before completion
            if visited[src] == 1:
                return False
            # Return true if the node is completed processing
            if visited[src] == 2:
                return True
            visited[src] = 1
            for dest in graph[src]:
                if not dfs(dest):
                    return False
            visited[src] = 2 # Mark as processed
            res.append(src)
            return True
        
        for c in range(numCourses):
            dfs(c)
        return res[::-1] if len(res) == numCourses else []
    
"""
Time and space complexity: O(v + e)
"""