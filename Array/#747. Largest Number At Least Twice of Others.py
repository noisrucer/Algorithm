class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_num, second_max_num = 0, 0
        res = 0

        for i in range(len(nums)):
            if nums[i] > max_num:
                second_max_num = max_num
                max_num = nums[i]
                res = i
            elif nums[i] < max_num and nums[i] > second_max_num:
                second_max_num = nums[i]

        return res if max_num >= 2 * second_max_num else -1