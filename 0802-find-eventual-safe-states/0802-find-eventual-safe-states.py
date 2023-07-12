class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        
        indegree = [0] * n
        adj = defaultdict(lambda: list())
        
        for src in range(n):
            for dest in graph[src]:
                adj[dest].append(src)
                indegree[src] += 1
        
        q = deque()
        
        for node in range(n):
            if indegree[node] == 0:
                q.append(node)
        
        safe = [False] * n
        
        while q:
            src = q.popleft()
            safe[src] = True
            
            for dest in adj[src]:
                indegree[dest] -= 1
                if indegree[dest] == 0:
                    q.append(dest)
        
        res = [i for i in range(n) if safe[i]]
        return res
                
        
    
        
        
        