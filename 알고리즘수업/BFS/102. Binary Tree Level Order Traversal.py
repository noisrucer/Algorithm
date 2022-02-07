# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []
        
        res = []
        Q = [] # queue
        Q.append(root)
        
        while len(Q):
            level_size = len(Q)
            level_array = []
            
            for i in range(level_size):
                cur = Q[0]
                Q.pop(0)
                level_array.append(cur.val)
                
                if cur.left is not None:
                    Q.append(cur.left)
                if cur.right is not None:
                    Q.append(cur.right)
                    
            res.append(level_array)
            
        
        return res