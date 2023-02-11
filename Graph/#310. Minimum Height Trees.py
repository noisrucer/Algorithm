class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        # edge = # node - 1
        adj = [[] for _ in range(n)]
        Q = deque()
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        for i in range(n):
            if len(adj[i]) == 1:
                Q.append(i)

        while n > 2:
            level_size = len(Q)
            n -= level_size
            for _ in range(level_size):
                curr = Q.popleft()
                for ngbr in adj[curr]:
                    adj[ngbr].remove(curr)
                    if len(adj[ngbr]) == 1:
                        Q.append(ngbr)
        print(Q)
        return list(Q)


        
