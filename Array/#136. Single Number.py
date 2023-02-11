'''
TC: O(n)
SC: O(1)
'''

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = nums[0]
        for i in range(1, n):
            res ^= nums[i]
        return res