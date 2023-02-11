''' 1D DP
f(i, j) = ith level의 j칸에서의 min path sum

Base case
f(0, 0) = triangle[0][0]

General case
f(i, j) = triangle[i][j] + min(f(i - 1, j), f(i - 1, j - 1))
'''
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m = len(triangle)
        dp = [inf for _ in range(m + 1)]
        dp[0] = triangle[0][0]


        for i in range(1, m):
            for j in range(i, -1, -1):
                dp[j] = triangle[i][j] + min(dp[j] if j < i else inf, dp[j - 1] if j > 0 else inf)

        return min(dp)


'''
f(i, j) = ith level의 j칸에서의 min path sum

Base case
f(0, 0) = triangle[0][0]

General case
f(i, j) = triangle[i][j] + min(f(i - 1, j), f(i - 1, j - 1))
'''
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m = len(triangle)
        dp = [[inf for _ in range(m)] for _ in range(m + 1)]

        dp[0][0] = triangle[0][0]

        for i in range(1, m):
            for j in range(i + 1):
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1])

        return min(dp[m - 1])