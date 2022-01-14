'''
1) 문제정의: tree의 maximum depth
2) 알고리즘: Tree
3) 자료구조: None
4) 해결전략: 
   - 일반화: f(r) : root r 트리의 maximum depth
   - f(r) = 1 + max(f(r.left), f(r.right))

<TIPS>
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        