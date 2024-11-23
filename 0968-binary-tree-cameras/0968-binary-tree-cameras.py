# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Lets say have_cam=2, need_cam=1, covered=0, camera_count=0
Now, if the left node says he needs camera (l==1) or right node says he needs camera (r==1) then parent node has no other option but to install the camera so that its child and he himself gets covered so camera count will increase (camera_count+=1) and parent says he has camera now (return 2)
If the left child says he has the camera (l==2) or right child says he has the camera (r==2) so now parent is covered (return 0)
If the left child says he is covered (l==0) or right child says he is covered (r==0) so now parent won't install the camera rather he will ask his parent to install the camera so that he gets covered so parent returns he need camera (return 1)
Lastly, we will check if root needs camera (1) because if root needs camera then he has no parent who can install the camera for him to get covered so he himself has to install the camera (camera_count+=1)
"""
class Solution:
    def dfs(self, root, camera):
        """have_cam=2, need_cam=1, covered=0"""
        if root is None:
            return 0
        left = self.dfs(root.left, camera)
        right = self.dfs(root.right, camera)
        if left == 1 or right == 1:
            camera[0] += 1
            return 2
        elif left == 2 or right == 2:
            return 0
        else:
            return 1
            
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        dummy = TreeNode(-1, root)
        camera = [0]
        self.dfs(dummy, camera)
        return camera[0]