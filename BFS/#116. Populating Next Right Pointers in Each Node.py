
class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None
        res = root
        Q = []
        Q.append(root)

        while Q:
            prev = None
            level_size = len(Q)
            for _ in range(level_size):
                curr = Q[0]
                Q.pop(0)
                if not prev: # leftmost
                    prev = curr
                else: # in-between
                    prev.next = curr
                    prev = curr
                
                if curr.left:
                    Q.append(curr.left)
                if curr.right:
                    Q.append(curr.right)
        return res