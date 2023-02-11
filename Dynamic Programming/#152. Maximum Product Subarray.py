'''
TC: O(n)
SC: O(1)
'''

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        glob_max = nums[0]
        cur_max, cur_min = nums[0], nums[0]

        for e in nums[1:]:
            temp_max, temp_min = cur_max, cur_min
            cur_max = max(e, temp_max * e, temp_min * e)
            cur_min = min(e, temp_max * e, temp_min * e)
            glob_max = max(glob_max, cur_max)

        return glob_max




