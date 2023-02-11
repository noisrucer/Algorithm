class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        # Inorder traversal
        self.res = []
        self.cnt = 0
        self.max_cnt = 0
        self.prev = None
        self.inorder(root)
        return self.res
        

    def inorder(self, root):
        if not root:
            return None

        self.inorder(root.left)
        self.cnt = 1 if root.val != self.prev else self.cnt + 1
        if self.cnt == self.max_cnt:
            self.res.append(root.val)
        elif self.cnt > self.max_cnt:
            self.res = [root.val]
            self.max_cnt = self.cnt
        self.prev = root.val
        self.inorder(root.right)