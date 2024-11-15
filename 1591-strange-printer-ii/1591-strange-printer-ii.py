class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        rows, cols = len(targetGrid), len(targetGrid[0])
        border = defaultdict(list)
        for i in range(rows):
            for j in range(cols):
                color = targetGrid[i][j]
                if color not in border:
                    border[color] = (i, i, j, j) # (xmin, xmax, ymin, ymax)
                else:
                    border[color] = (
                        min(i, border[color][0]),
                        max(i, border[color][1]),
                        min(j, border[color][2]),
                        max(j, border[color][3])
                    )
        colors = list(border.keys())
        graph = defaultdict(set)
        for c in colors:
            for i in range(border[c][0], border[c][1] + 1):
                for j in range(border[c][2], border[c][3] + 1):
                    if targetGrid[i][j] != c:
                        graph[targetGrid[i][j]].add(c)
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
            return True
        return all(dfs(c) for c in colors)
    
    """
    Time: O(m * n * c)
    Space: O(c ^ 2)
    """
            
                
        