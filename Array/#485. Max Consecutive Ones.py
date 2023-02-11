class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        nums.append(0)
        cnt = 0
        res = 0

        for e in nums:
            if e == 0:
                res = max(res, cnt)
                cnt = 0
            else:
                cnt += 1

        return res