class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Create a graph and an indegree list
        graph = defaultdict(list)
        indegree = [0] * numCourses
        
        # Build the graph and indegree list
        for u, v in prerequisites:
            indegree[u] += 1
            graph[v].append(u)
        
        # Initialize a queue with courses that have no prerequisites
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        # for node in range(numCourses):
        #     if indegree[node] == 0:
        #         queue.append(node)
        
        # Process the queue
        done = 0
        while queue:
            src = queue.popleft()
            done += 1
            for dest in graph[src]:
                indegree[dest] -= 1
                if indegree[dest] == 0:
                    queue.append(dest)
        
        # Check if all courses can be finished
        return done == numCourses