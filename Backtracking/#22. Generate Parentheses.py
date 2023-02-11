'''
TC: O(2^n)
SC: O(2^n)
'''


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.helper(n, n, 0, "")
        return self.res


    def helper(self, left, right, offset, temp):
        if offset < 0:
            return None
            
        if left < 0 or right < 0:
            return None

        if left == 0 and right == 0:
            self.res.append(''.join(temp[:]))
            return None

        self.helper(left - 1, right, offset + 1, temp + "(")
        self.helper(left, right - 1, offset - 1, temp + ")")
