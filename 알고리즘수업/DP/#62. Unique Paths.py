class Solution:
    def topdown(self, dp, m, n, i, j):
        if i<0 or j<0:
            return 0
        if i==0 and j==0:
            return 1
        if dp[i][j] is not -1:
            return dp[i][j]
        
        dp[i][j] = self.topdown(dp,m,n,i-1,j) + self.topdown(dp,m,n,i,j-1)
        return dp[i][j]
        
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        return self.topdown(dp,m,n,m-1,n-1);
        