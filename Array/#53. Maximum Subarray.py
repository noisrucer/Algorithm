class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Kadane's algorithm
        cur_max, glob_max = -math.inf, -math.inf
        for e in nums:
            cur_max = max(cur_max + e, e)
            glob_max = max(glob_max, cur_max)

        return glob_max