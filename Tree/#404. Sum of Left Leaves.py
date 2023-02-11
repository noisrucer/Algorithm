'''
TC: O(n)
SC: O(n) for call stacks
'''

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode], left=None) -> int:
        if not root:
            return 0

        if not root.left and not root.right and left:
            return root.val

        return self.sumOfLeftLeaves(root.left, True) + self.sumOfLeftLeaves(root.right, False)