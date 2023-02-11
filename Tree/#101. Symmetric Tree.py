class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.helper(root.left, root.right)

    def helper(self, l, r):
        if not l and not r:
            return True
        if not l or not r:
            return False

        return l.val == r.val and self.helper(l.left, r.right) and self.helper(l.right, r.left)