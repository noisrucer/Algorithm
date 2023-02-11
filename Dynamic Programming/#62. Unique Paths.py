'''
TC: O(mn)
SC: O(mn)
'''

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        self.dp = [[-1 for _ in range(n)] for _ in range(m)]
        return self.topdown(m - 1, n - 1)


    def topdown(self, i, j):
        if i == 0 and j == 0:
            return 1
        
        if i < 0 or j < 0:
            return 0

        if self.dp[i][j] != -1:
            return self.dp[i][j]

        self.dp[i][j] = self.topdown(i - 1, j) + self.topdown(i, j - 1)
        return self.dp[i][j]