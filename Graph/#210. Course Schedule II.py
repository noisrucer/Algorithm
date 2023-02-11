'''
TC: O(V + E)
SC: O(V^2)
'''
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        res = []
        adj = [[] for _ in range(numCourses)]
        indegrees = [0 for _ in range(numCourses)]
        Q = []

        for pre in prerequisites:
            adj[pre[1]].append(pre[0])
            indegrees[pre[0]] += 1

        for i in range(numCourses):
            if indegrees[i] == 0:
                Q.append(i)

        while Q:
            curr = Q[0]
            Q.pop(0)
            res.append(curr)

            for ngbr in adj[curr]:
                indegrees[ngbr] -= 1
                if indegrees[ngbr] == 0:
                    Q.append(ngbr)

        return res if len(res) == numCourses else []

        