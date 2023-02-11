'''
TC: O(n^2)
SC: O(n^2)
'''

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        '''
        [STEP 1]
        Memoize dp[i][j] = whether s[i: j + 1] is a palindrome

        [STEP 2]
        1) Given an index "start", find all possible palindrome partitions of s[start:]
        2) Define g(start) = all possible partitions of s[start: ], (2D list)
        3) For i in range [start, n - 1], divide the array into
            - s[start: i + 1] and g(i + 1) recursively
        '''
        res = []
        self.n = len(s)
        self.dp = [[False for _ in range(self.n)] for _ in range(self.n)]

        for i in range(self.n):
            self.dp[i][i] = True
            if i < self.n - 1:
                self.dp[i][i + 1] = (s[i] == s[i + 1])

        for length in range(3, self.n + 1):
            for i in range(self.n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    self.dp[i][j] = self.dp[i + 1][j - 1]

        return self.helper(s,  0)

        
    def helper(self, s, start):
        if start >= self.n:
            return [[]]

        if start == self.n - 1:
            return [[s[self.n - 1]]]
        
        res = []
        for i in range(start, self.n):
            if self.dp[start][i]:
                right_partition = self.helper(s, i + 1)
                for chunk in right_partition:
                    res.append([s[start: i + 1]] + chunk)
        return res


        