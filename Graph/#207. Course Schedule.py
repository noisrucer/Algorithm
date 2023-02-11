''' Method 1 - BFS (indegrees)
TC: O(V + E)
SC: O(V^2) for adj list
'''
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Initialize Adj. list, indegrees, and Queue
        adj = [[] for _ in range(numCourses)]
        indegrees = [0 for _ in range(numCourses)]
        Q = deque()

        # Construct Adj. list
        for pre in prerequisites:
            adj[pre[1]].append(pre[0])
            indegrees[pre[0]] += 1

        # Push all zero indegree nodes
        for i in range(numCourses):
            if indegrees[i] == 0:
                Q.append(i)

        # Perform BFS
        num_zero_indegrees = 0
        while Q:
            curr = Q.popleft()
            num_zero_indegrees += 1
            for ngbr in adj[curr]:
                indegrees[ngbr] -= 1
                if indegrees[ngbr] == 0:
                    Q.append(ngbr)

        # All nodes must have zero indegree
        return num_zero_indegrees == numCourses

        
''' Method 2 - DFS
TC: O(V + E)
SC: O(V^2)
'''
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        self.visited = [0 for _ in range(numCourses)]

        for pre in prerequisites: # construct adj list
            adj[pre[1]].append(pre[0])

        for v in range(numCourses):
            if self.visited[v] == 2:
                continue
            if self.detectCycle(adj, v): # If there's a cycle, can't finish
                return False
        return True
                

    def detectCycle(self, adj, curr):
        if self.visited[curr] == 1: # cycle detected
            return True
        
        if self.visited[curr] == 2: # already visited (no cycle)
            return False

        self.visited[curr] = 1 # mark it as "temporary visit"

        for ngbr in adj[curr]:
            if self.detectCycle(adj, ngbr): # detect cycle in ngbr
                return True

        self.visited[curr] = 2 # mark as "real visit"
        return False
    
    
'''Method 3 - Backtracking
'''
def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i:[] for i in range(numCourses)} #

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visitSet = set()
        def dfs(crs):
            if crs in visitSet:
                return False
            if preMap[crs] == []:
                return True

            visitSet.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre): return False
            visitSet.remove(crs)
            preMap[crs] = []
            return True
        
        for crs in range(numCourses):
            if not dfs(crs): return False
        return True