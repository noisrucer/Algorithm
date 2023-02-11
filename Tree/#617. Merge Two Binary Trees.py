class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root1, root2)

    def dfs(self, r1, r2):
        if r1 and r2:
            r1.val += r2.val
        elif r1:
            return r1
        elif r2:
            return r2
        else:
            return None
        
        r1.left = self.dfs(r1.left, r2.left)
        r1.right = self.dfs(r1.right, r2.right)
        return r1
        