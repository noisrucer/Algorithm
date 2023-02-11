'''
TC: O(logn)
SC: O(logn)

[Description]

For a number n, the # of digits is approximately logn.
For 4 digit number, the maximum "next" number it can take is 9^2 * 4 = 324.
For 3 digit number, the maximum "next" number it can take is 9*2 * 3 = 243
...
'''

class Solution:
    def isHappy(self, n: int) -> bool:
        visit = set()
        while n != 1:
            temp = 0
            for i in str(n):
                temp += int(i) ** 2
            if temp in visit:
                return False
            visit.add(temp)
            n = temp

        return True