class Graph:
    def __init__(self, n):
        self.vertices = n
        self.graph = defaultdict(set)
        self.visited = [False] * n
        self.parent = [-1] * n

    def add_edge(self, u, v):
        self.graph[u].add(v)
    
    def dfs(self, src, visited, rec_stack, cycle):
        visited[src] = True
        rec_stack[src] = True
        cycle[0] += 1
        for dest in self.graph[src]:
            if not visited[dest]:
                if self.dfs(dest, visited, rec_stack, cycle):
                    return True
            elif rec_stack[dest]:
                return True
        rec_stack[src] = False
        cycle[0] -= 1
        return False
    
    def longest_cycle(self):
        maxlength = -1
        visited, rec_stack = [False] * self.vertices, [False] * self.vertices 
        for src in range(self.vertices):
            if not self.visited[src]:
                cycle = [0]
                if self.dfs(src, visited, rec_stack, cycle):
                    maxlength = max(maxlength, cycle[0])
        return maxlength

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        graph = Graph(len(edges))
        for i, v in enumerate(edges):
            if v != -1:
                graph.add_edge(v, i)
        return graph.longest_cycle()