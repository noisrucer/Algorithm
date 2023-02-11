'''
TC: O(n^2)
SC: O(n)
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        '''
        f(start) = Whether s[start:] can be segmented into dict words
        f(start) = s[:k+1] and f(k+1) for some k in [start, len(s) - 1]
        '''
        self.words = set(wordDict)
        self.dp = [-1 for _ in range(len(s))]
        return self.dfs(s, 0)


    def dfs(self, s, start):
        if start == len(s):
            return True

        if self.dp[start] != -1:
            return self.dp[start]

        possible = False
        for end in range(start, len(s)):
            if s[start: end + 1] in self.words:
                possible = possible or self.dfs(s, end + 1)
                if possible:
                    break

        self.dp[start] = possible 
        return possible
    
    
'''
TC: O(n^2)
SC: O(n)
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        d = [False] * len(s)    
                for i in range(len(s)):
                    for w in wordDict:
                        if w == s[i:i+len(w)] and (i==0 or d[i-1]==True): 
                            d[i+len(w)-1]=True
        return d[-1]