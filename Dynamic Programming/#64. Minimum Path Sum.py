''' Method 1 - Topdown
f(i, j) = min path sum from (0, 0) to (i, j)

[Base case]
f(0, 0) = grid[i][j]
f(i < 0 or j < 0) = 0

[General case]
f(i, j) = grid[i][j] + min(f(i - 1, j), f(i, j - 1))
'''
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        self.dp = [[-1 for _ in range(n)] for _ in range(m)]
        return self.topdown(grid, m - 1, n - 1)

    def topdown(self, grid, i, j):
        if i == 0 and j == 0:
            return grid[i][j]

        if i < 0 or j < 0:
            return inf

        if self.dp[i][j] != -1:
            return self.dp[i][j]

        self.dp[i][j] = grid[i][j] + min(self.topdown(grid, i - 1, j), self.topdown(grid, i, j - 1))

        return self.dp[i][j]
    
    
''' Method 2 - Bottom up
'''
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[inf for _ in range(n + 1)] for _ in range(m + 1)]
        dp[1][1] = grid[0][0]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if i == 1 and j == 1:
                    continue
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]