class Solution:
    def numTrees(self, n: int) -> int:
        self.dp = [-1 for _ in range(n + 1)]
        return self.topdown(n)

    def topdown(self, n):
        if n == 0:
            return 1
        if n == 1:
            return 1

        if self.dp[n] != -1:
            return self.dp[n]

        cnt = 0
        for i in range(n):
            cnt += self.topdown(i) * self.topdown(n - 1 - i)
        self.dp[n] = cnt
        return self.dp[n]

        
        