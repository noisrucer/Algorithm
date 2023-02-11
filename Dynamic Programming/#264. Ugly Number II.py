class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n <= 0:
            return False
        dp = [0 for _ in range(n)]
        dp[0] = 1
        i2, i3, i5 = 0, 0, 0
        for i in range(1, n):
            next = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)
            if next == dp[i2] * 2:
                i2 += 1
            if next == dp[i3] * 3:
                i3 += 1
            if next == dp[i5] * 5:
                i5 += 1
            dp[i] = next
        return dp[n - 1]

    