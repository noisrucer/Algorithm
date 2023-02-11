'''
TC: O(logn)
SC: O(1)
'''
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""
        columnNumber -= 1
        while columnNumber >= 0:
            remainder = columnNumber % 26
            columnNumber = columnNumber // 26 - 1
            res = chr(ord('A') + remainder) + res

        return res
            
            