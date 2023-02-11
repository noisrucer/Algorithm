'''
TC: O(n^2)
SC: O(n^2)
'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        max_len = 1
        res = s[0]
        dp = [[0 for _ in range(n)] for _ in range(n)]

        # Base Case
        for i in range(0, n - 1):
            dp[i][i] = 1
            if i < n - 1 and s[i] == s[i + 1]:
                dp[i][i + 1] = 1
                res = max(res, s[i:i+2], key=lambda x: len(x))

        # General Case
        for length in range(3, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = 1
                    res = max(res, s[i:j+1], key=lambda x: len(x))

        return res