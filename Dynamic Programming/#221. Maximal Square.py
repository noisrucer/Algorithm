'''
[2D DP]
dp[i][j] = largest square with the bottom-right edge at (i, j)

> Base case
dp[0][0], dp[i][0], dp[0][j] = matrix[i][j] == '1'

> General case
dp[i][j] = (matrix[i][j] == '1) + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

[1D DP]
Notice we're only accessing cache one right before the current index (e.g. i-1, j-1, i-1 & j-1).
Hence, we can use 1D cache.
For dp[i-1][j], we can use dp[j]
For dp[i][j-1], we can use dp[j - 1]
For dp[i-1][j-1], we can store this value as a separate variable "diag".
Suppose currently we're at (i, j), then we store dp[j] to "diag" so that (i, j+1) could access this
'''

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [0 for _ in range(n + 1)]
        diag = 0
        res = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                temp = dp[j]
                if matrix[i - 1][j - 1] == '1':
                    dp[j] = 1 + min(dp[j], dp[j - 1], diag)
                else:
                    dp[j] = 0
                res = max(res, dp[j])
                diag = temp
            diag = 0

        return res ** 2
    
    
    

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [0 for _ in range(n + 1)]
        diag = 0
        res = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                temp = dp[j]
                is_one = (matrix[i - 1][j - 1] == '1')
                dp[j] = is_one + min(dp[j], dp[j - 1], diag) if is_one else 0
                res = max(res, dp[j])
                diag = temp
            diag = 0

        return res ** 2

        


