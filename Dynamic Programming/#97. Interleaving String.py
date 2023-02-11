''' 1D DP
'''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        dp = [0 for _ in range(n + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    dp[j] = True
                elif i == 0:
                    dp[j] = (s2[j - 1] == s3[i + j - 1] and dp[j - 1])
                elif j == 0:
                    dp[j] = (s1[i - 1] == s3[i + j - 1] and dp[j])
                else:
                    dp[j] = (s1[i - 1] == s3[i + j - 1] and dp[j]) or (s2[j - 1] == s3[i + j - 1] and dp[j - 1])

        return dp[n]



''' 2D DP 
f(i, j) = Whether s2[: i + j + 2] can be formed by an interleaving of s1[: i + 1] and s2[: j + 1]

Base case
f(i, 0) = (s1[i] == s3[i]) and (f(i - 1, 0) == True)
f(0, j) = (s2[j] == s3[j]) and (f(0, j - 1) == True)

General case
f(i, j) = (s1[i] == s3[i + j + 1] and f(i - 1, j)) or (s2[j] == s3[i + j + 1] and f(i, j - 1))
'''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False

        dp = [[False for _ in range(n + 1)] for _ in range(m + 1)]

        # Base case
        dp[0][0] = True
        for i in range(1, m + 1):
            dp[i][0] = (s1[i - 1] == s3[i - 1]) and dp[i - 1][0] == True

        for j in range(1, n + 1):
            dp[0][j] = (s2[j - 1] == s3[j - 1]) and dp[0][j - 1] == True

        # General case
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) or (s2[j - 1] == s3[i + j - 1] and dp[i][j - 1])

        return dp[m][n]
