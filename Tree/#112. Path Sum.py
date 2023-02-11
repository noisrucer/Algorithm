
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int, path_sum = 0) -> bool:
        if not root:
            return False

        if root.left is None and root.right is None:
            return path_sum + root.val == targetSum

        return self.hasPathSum(root.left, targetSum, path_sum + root.val) or self.hasPathSum(root.right, targetSum, path_sum + root.val)
        