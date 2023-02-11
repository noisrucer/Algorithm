# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.topdown(root)
        return self.res

    def topdown(self, root):
        if not root:
            return None

        self.res.append(root.val)
        self.topdown(root.left)
        self.topdown(root.right)