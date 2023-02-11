''' Method 1 - dequeue
'''
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        res = []
        deq = deque()
        deq.append(root)
        level = 1
        while deq:
            level_size = len(deq)
            temp = []
            for _ in range(level_size):
                if level & 1:
                    cur = deq[0]
                    deq.popleft()
                    if cur.left:
                        deq.append(cur.left)
                    if cur.right:
                        deq.append(cur.right)
                else:
                    cur = deq[-1]
                    deq.pop()
                    if cur.right:
                        deq.appendleft(cur.right)
                    if cur.left:
                        deq.appendleft(cur.left)
                
                temp.append(cur.val)
            res.append(temp)
            level += 1
        return res


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: # Base Case
            return []
        res = []
        Q = [root]
        level = 1
        while len(Q):
            level_size = len(Q)
            temp = []
            for i in range(level_size):
                cur = Q[0]
                Q.pop(0)
                if level & 1:
                    temp.append(cur.val)
                else:
                    temp = [cur.val] + temp
                if cur.left:
                    Q.append(cur.left)
                if cur.right:
                    Q.append(cur.right)
            res.append(temp)
            level += 1

        return res