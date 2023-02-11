class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj = defaultdict(dict)
        visited = set()
        res = []

        for i in range(len(equations)):
            eq, val = equations[i], values[i]
            adj[eq[0]][eq[1]] = val
            adj[eq[1]][eq[0]] = 1 / val

        for q in queries:
            if q[0] not in adj.keys() or q[1] not in adj.keys():
                res.append(-1.0)
                continue
            visited = set()
            div = self.dfs(adj, visited, q[0], q[1], 1.0)
            res.append(div if div != 0 else -1.0)

        return res

        
    def dfs(self, adj, visited, curr, des, running_div):
        if curr == des:
            return running_div

        visited.add(curr)
        res = 0
        for ngbr in adj[curr].keys():
            if ngbr in visited:
                continue
            res = self.dfs(adj, visited, ngbr, des, running_div * adj[curr][ngbr])
            
            if res != 0:
                return res

        return 0