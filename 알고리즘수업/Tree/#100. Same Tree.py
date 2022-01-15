# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
점화식: f(p,q) = Are tree p and q the same?

Base Case:
1) if p==None AND q==None ?
2) ONLY ONE of p and q is None ?
3) if p.val != q.val ?

General Case:
1) GIVEN current p, q have the same values(which means passed all the base cases),
f(p,q) = f(p.left, q.left) AND f(p.right, q.right) 
'''
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None: # is both None -> same
            return True
        if p is None or q is None: # if ONLY one of them is None -> different
            return False
        
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
        