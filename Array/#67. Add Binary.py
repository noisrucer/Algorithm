'''
TC: O(max(n, m))
SC: O(1)
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        len_a, len_b = len(a), len(b)
        i, j = len_a - 1, len_b - 1

        carry = 0
        while i >= 0 or j >= 0:
            curr = 0
            if i >= 0:
                curr += int(a[i])
            if j >= 0:
                curr += int(b[j])
            curr += carry

            digit = curr % 2
            carry = curr // 2

            res = str(digit) + res
            i -= 1
            j -= 1
        
        if carry:
            res = "1" + res

        return res