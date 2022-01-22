# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode], val = None) -> bool:
        if root is None:
            return True
        
        if val is None:
            val = root.val
        else:
            if root.val is not val:
                return False
        
        return self.isUnivalTree(root.left, val) and self.isUnivalTree(root.right, val)
        
        