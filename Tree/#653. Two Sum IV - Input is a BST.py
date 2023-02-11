class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        bst_iter = BSTIterator(root)
        left, right = bst_iter.next_left(), bst_iter.next_right()
        while left < right:
            if left + right == k:
                return True
            elif left + right < k:
                left = bst_iter.next_left()
            else:
                right = bst_iter.next_right()
        return False
        

class BSTIterator:
    def __init__(self, root):
        self.stack_left = []
        self.stack_right = []
        temp = root
        self.push_all_left(root)
        self.push_all_right(temp)


    def next_left(self):
        top = self.stack_left.pop()
        self.push_all_left(top.right)
        return top.val


    def next_right(self):
        top = self.stack_right.pop()
        self.push_all_right(top.left)
        return top.val


    def push_all_left(self, node):
        while node:
            self.stack_left.append(node)
            node = node.left


    def push_all_right(self, node):
        while node:
            self.stack_right.append(node)
            node = node.right