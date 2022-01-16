# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
점화식: f(node) = node를 root로 하는 tree에서 target node를 반환
Base Case
1) if node is None ?

Genera Case
1) if target < node.val ?
2) if target > node.val ?
3) if target == node.val ?
'''
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        def help(root):
            if root is None: # if there's no node, there's no way we can find the target, obviouisly
                return None
            
            if root.val == val: # We found the target!
                return root
            
            if val > root.val: # If the target > current node's value, go to RIGHT. Why?
                return help(root.right)
            else: # If the target < current node's value, go to LEFT.
                return help(root.left)
            
        return help(root)
    
    
    
int sum = 0

int a = 1;

if(a == 1){
    sum++;
}

sum += (a == 1)

cout<<sum;