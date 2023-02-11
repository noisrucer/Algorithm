class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        n = len(s)
        i = n - 1
        res = 0
        while i >= 0:
            if s[i] != ' ':
                res += 1
            else:
                break

            i -= 1

        return res