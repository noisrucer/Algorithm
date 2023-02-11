''' Method 1 - DFS
TC: O(V + E)
SC: O(V)
'''
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        self.copy = dict()
        return self.dfs(node)


    # Returns copy of original node
    def dfs(self, node):
        if node.val in self.copy:
            return self.copy[node.val]

        self.copy[node.val] = Node(node.val)
        for neighbor in node.neighbors:
            self.copy[node.val].neighbors.append(self.dfs(neighbor))
        
        return self.copy[node.val]
    
''' Method 2 - BFS
TC: O(V + E)
SC: O(V)
'''

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
            
        Q = deque([node])
        copy = {node.val: Node(node.val)}
        
        while Q:
            curr = Q.popleft()
            for neighbor in curr.neighbors:
                if neighbor.val not in copy:
                    copy[neighbor.val] = Node(neighbor.val)
                    Q.append(neighbor)
                copy[curr.val].neighbors.append(copy[neighbor.val])

        return copy[node.val]
