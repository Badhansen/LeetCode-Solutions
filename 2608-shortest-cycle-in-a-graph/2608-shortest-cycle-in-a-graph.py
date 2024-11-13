class Graph:
    def __init__(self, n):
        self.vertices = n
        self.graph = defaultdict(set)
        self.visited = [False] * n
        self.parent = [-1] * n
        self.cycle_start = -1
        self.cycle_end = -1
        
    def add_edge(self, u, v):
        self.graph[u].add(v)
        self.graph[v].add(u)
    
    def find_cycles_min_length(self):
        cycle = float("inf")
        for src in range(self.vertices):
            dist = [float("inf")] * self.vertices
            dist[src] = 0
            queue = deque([(src, -1)]) # (node, parent)
            while queue:
                u, parent = queue.popleft()
                for v in self.graph[u]:
                    if dist[v] == float("inf"):
                        dist[v] = dist[u] + 1
                        queue.append((v, u))
                    elif v != parent:
                        cycle = min(cycle, dist[u] + dist[v] + 1)
        return -1 if cycle == float("inf") else cycle
    
class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        graph = Graph(n)
        for u, v in edges:
            graph.add_edge(u, v)
        return graph.find_cycles_min_length()
        