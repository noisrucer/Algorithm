class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        original = num
        cnt = 0
        while num > 10 ** (k - 1) - 1:
            chunk = num % (10 ** k)
            if chunk != 0 and original % chunk == 0:
                cnt += 1
            num //= 10
        return cnt