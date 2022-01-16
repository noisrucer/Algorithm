# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
점화식: f(node) = node를 root로 하는 (sub)tree에서 [low,high]에 들어가는 모든 수의 합을 반환 (it'd be amazing if we take advantage of BST!)
Base Case: 
    1) if node is None ?
General Case:
    1) if node.val < low ?
    2) if node.val > high ?
    3) if low <= node.val <= high ?

'''
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:  
        def help(root):
            if root is None: # If there's nothing, then obviously we cannot find anything
                return 0
            if root.val < low: # If current node's value is too small, we should look for greater values -> go to RIGHT
                return help(root.right)
            elif low <= root.val and root.val <= high: # The current node's value falls in the window
                return root.val + help(root.left) + help(root.right)
            else: # If current node's value is too large, we should look for smaller values -> go to LEFT
                return help(root.left)
                
        return help(root)
                
            
            