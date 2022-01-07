# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:  
        
        def help(root):
            if root is None:
                return 0
            if root.val < low:
                return help(root.right)
            elif low <= root.val and root.val <= high:
                return root.val + help(root.left) + help(root.right)
            else:
                return help(root.left)
                
        return help(root)
                
            
            