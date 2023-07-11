# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = defaultdict(lambda: [])
        
        def dfs(root):
            if not root:
                return None
            
            left = dfs(root.left)
            right = dfs(root.right)
            
            if left:
                graph[root.val].append(left.val)
                graph[left.val].append(root.val)
            if right:
                graph[root.val].append(right.val)
                graph[right.val].append(root.val)
        
            return root
        
        dfs(root)
        
        q = collections.deque()
        q.append(target.val)
        res = []
        visited = set()
        level = 0
        visited.add(target.val)
        
        while q and level < k:
            size = len(q)
            while size:
                src = q.popleft()
                size -= 1
                for dest in graph[src]:
                    if dest not in visited:
                        visited.add(dest)
                        q.append(dest)
            level += 1;
        while q:
            res.append(q.popleft())
    
        return res 
            
            
            
            