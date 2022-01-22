# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode], val = 0) -> int:
        if root is None:
            return 0;
        val = val*2 + root.val
        if root.left is None and root.right is None:
            return val
        else:
            return self.sumRootToLeaf(root.left, val) + self.sumRootToLeaf(root.right, val)
        