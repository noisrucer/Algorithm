# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        
        def inorder(root):
            if root is None:
                return 0
            inorder(root.left)
            res.append(root.val)
            inorder(root.right)
        
        inorder(root)
        return res
    
    
    f(root.left) = root를 맨 꼭대기로 하는 tree의 inorder traversal을 출력하라