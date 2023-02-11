# Definition for a binary tree node.
'''
TC: O(n), n = # of nodes
SC: O(n)
'''

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: # Base Case
            return []
        res = []
        Q = [root]
        while len(Q):
            level_size = len(Q)
            temp = []
            for i in range(level_size):
                cur = Q[0]
                Q.pop(0)
                temp.append(cur.val)
                if cur.left:
                    Q.append(cur.left)
                if cur.right:
                    Q.append(cur.right)
            res.append(temp)

        return res
