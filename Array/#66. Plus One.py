'''
TC: O(n)
SC: O(1)
'''
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits) # O(1)
        carry = 1
        for i in range(n - 1, -1, -1): # O(n)
            cur = digits[i] + carry
            digit = cur % 10
            carry = cur // 10
            digits[i] = digit

        return digits if not carry else [1] + digits