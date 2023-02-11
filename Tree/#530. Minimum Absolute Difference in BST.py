class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.prev = None
        self.min_diff = math.inf
        self.inorder(root)
        return self.min_diff

    def inorder(self, root):
        if not root:
            return None
        self.inorder(root.left)
        if self.prev is not None:
            self.min_diff = min(self.min_diff, root.val - self.prev)
        self.prev = root.val
        self.inorder(root.right)
        