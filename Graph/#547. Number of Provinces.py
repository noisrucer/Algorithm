class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        # Find # of connected components
        cnt = 0
        n = len(isConnected)
        visited = [False for _ in range(n)]
        for i in range(n):
            if visited[i]:
                continue
            cnt += 1
            self.dfs(isConnected, visited, i)
        return cnt

        
    def dfs(self, adj, visited, curr):
        if visited[curr]:
            return None

        visited[curr] = True
        for ngbr in range(len(adj)):
            if adj[curr][ngbr] and not visited[ngbr]:
                self.dfs(adj, visited, ngbr)
            