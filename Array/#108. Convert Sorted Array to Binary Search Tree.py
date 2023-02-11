''' Method 1 - recursion
TC: O(n)
SC: O(n) for call stacks
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        return self.topdown(nums, 0, n - 1)

    def topdown(self, nums, l, r):
        if l > r:
            return None
        m = (l + r) // 2
        node = TreeNode(val=nums[m])
        node.left = self.topdown(nums, l, m - 1)
        node.right = self.topdown(nums, m + 1, r)
        return node
