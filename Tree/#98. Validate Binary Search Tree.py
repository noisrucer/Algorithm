'''
TC: O(n), n = # nodes
SC: O(n) for call stacks
'''

class Solution:
    def isValidBST(self, root: Optional[TreeNode], left=-inf, right=inf) -> bool:
        if not root:
            return True

        if not (left < root.val < right):
            return False

        return self.isValidBST(root.left, left, root.val) and self.isValidBST(root.right, root.val, right)
        