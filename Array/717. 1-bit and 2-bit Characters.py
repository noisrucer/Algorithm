class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits) 
        ones = 0
        for i in range(n - 2, -1, -1):
            if bits[i] == 0:
                break
            ones += 1

        return ones % 2 == 0
