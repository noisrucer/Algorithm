'''
TC: O(n)
SC: O(1)
'''

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        res = 0
        n = len(columnTitle)

        for i in range(n - 1, -1, -1):
            pos = (n - 1) - i
            offset = ord(columnTitle[i]) - ord('A')
            res += (26 ** pos) * (offset + 1)

        return res
