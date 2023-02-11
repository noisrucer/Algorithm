class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        self.adj = [[] for _ in range(n)]
        self.visited = [False for _ in range(n)]
        for v1, v2 in edges:
            self.adj[v1].append(v2)
            self.adj[v2].append(v1)

        return self.dfs(source, destination)

    def dfs(self, curr, dest):
        if self.visited[curr]:
            return False
        self.visited[curr] = True

        if curr == dest:
            return True

        for ngbr in self.adj[curr]:
            if self.dfs(ngbr, dest):
                return True

        # visited[cur] = false; 
        # We don't need this because if there's no path from a node, then it's game-over for that node. 
        # There's no way that you can revisit this node and make a path later out of nowhere!
        return False
