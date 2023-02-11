'''
TC: O(n)
SC: O(n)
'''
class Solution:
    def numDecodings(self, s: str) -> int:
        '''
        f(i) = # of decode ways of s[i:]
        [Base Case]
        f(i) = 1, if i >= n
        f(i) = f(i + 1) + f(i + 2), if i < n - 1 && 1 <= s[i:i+2] <= 26
        f(i) = f(i + 2) if > 26
        '''
        self.n = len(s)
        self.dp = [-1 for _ in range(self.n)]
        return self.topdown(s, 0)


    def topdown(self, s, i):
        if i >= self.n:
            return 1

        if s[i] == '0':
            return 0

        if self.dp[i] != -1:
            return self.dp[i]

        if i < self.n - 1 and int(s[i:i+2]) <= 26:
            self.dp[i] = self.topdown(s, i + 1) + self.topdown(s, i + 2)
        else:
            self.dp[i] = self.topdown(s, i + 1)

        return self.dp[i]
        