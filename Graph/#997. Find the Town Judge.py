class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        town_judge = -1
        indegree = [0] * n
        for p1, p2 in trust:
            indegree[p2 - 1] += 1
            indegree[p1 - 1] -= 1

        for i in range(n):
            if indegree[i] == n - 1:
                town_judge = i + 1

        return town_judge