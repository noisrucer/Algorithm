class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        start = 0
        n = len(s)
        i, j = 0, None
        while start < n:
            if n - start < k:
                s[start:] = s[start:][::-1]
            else:
                i = start
                j = i + k - 1
                s[i: j + 1] = s[i: j + 1][::-1]
            start += 2 * k
        return ''.join(s)
        