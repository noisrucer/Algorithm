'''
TC: O(n)
SC: O(1)
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.is_balanced = True
        self.height(root)
        return self.is_balanced

    
    def height(self, root):
        if not root:
            return 0
        
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        if abs(left_height - right_height) > 1:
            self.is_balanced = False

        return 1 + max(left_height, right_height)
        