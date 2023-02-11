class Solution:
    def countSegments(self, s: str) -> int:
        n = len(s)
        cnt = 0
        for i in range(n):
            if s[i] != ' ' and (i == 0 or s[i - 1] == ' '):
                cnt += 1
        return cnt