# Solution 1 - DFS
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode], left=False) -> int:
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return root.val if left else 0
        
        return self.sumOfLeftLeaves(root.left, True) + self.sumOfLeftLeaves(root.right, False)
  
    
# Solution 2 - BFS
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        res = 0
        Q = []
        Q.append([root, False])
        
        while len(Q):
            cur, isLeft = Q.pop(0)
            
            if (cur.left==None and cur.right==None) and isLeft:
                res += cur.val
                
            if cur.left:
                Q.append([cur.left, True])
            if cur.right:
                Q.append([cur.right, False])

                    
        return res