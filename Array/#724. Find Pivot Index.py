class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        total_sum = sum(nums)
        running_sum = 0
        for i, e in enumerate(nums):
            if total_sum - e - running_sum == running_sum:
                return i

            running_sum += e

        return -1