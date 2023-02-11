'''
TC: O(n), n = # of nodes
SC: O(1)
'''
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.inorder(root)
        return self.res

    def inorder(self, root):
        if not root:
            return None

        self.inorder(root.left)
        self.res.append(root.val)
        self.inorder(root.right)
        