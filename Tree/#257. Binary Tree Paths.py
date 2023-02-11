# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.res = []
        self.topdown(root, "")
        return self.res

    def topdown(self, root, path):
        if not root:
            return None

        if not root.left and not root.right:
            path += f"{root.val}"
            self.res.append(path)
            return None

        self.topdown(root.left, path + f"{root.val}->")
        self.topdown(root.right, path + f"{root.val}->")
            