'''
TC: O(n)
SC: O(1)
'''
class Solution:
    def isValid(self, s: str) -> bool:
        # TC: O(n)
        # SC: O(1)
        s = list(s)
        mapping = {')':'(', ']':'[', '}':'{'}
        top = -1

        for e in s:
            if e in mapping.values():
                top += 1
                s[top] = e
            else:
                if top == -1 or s[top] != mapping[e]:
                    return False
                top -= 1

        return top == -1