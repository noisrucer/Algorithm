class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        m, n = len(num1), len(num2)
        i, j = m - 1, n - 1
        carry = 0
        res = ""

        while i >= 0 or j >= 0:
            curr = 0
            if i >= 0:
                curr += int(num1[i])
            if j >= 0:
                curr += int(num2[j])
            curr += carry

            digit = curr % 10
            carry = curr // 10
            res = str(digit) + res
            i -= 1
            j -= 1

        if carry:
            res = "1" + res

        return res
        