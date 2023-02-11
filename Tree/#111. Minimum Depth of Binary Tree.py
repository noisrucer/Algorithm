class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        min_d = None
        if not root.left or not root.right:
            return 1 + max(self.minDepth(root.left), self.minDepth(root.right))
        else:
            return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
            