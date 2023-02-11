class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        max_len = 1
        cnt = 1
        for i in range(1, n):
            cnt = cnt + 1 if nums[i] > nums[i - 1] else 1
            max_len = max(max_len, cnt)
        return max_len
