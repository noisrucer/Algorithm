'''Method1
TC: O(n)
SC: O(1)
'''

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n == 0:
            return []

        nums.append(nums[len(nums) - 1] + 2) # dummy data
        res = []
        start, prev = 0, 0 # index

        for i in range(1, len(nums)):
            if nums[i] != nums[prev] + 1:
                res.append(f"{nums[start]}->{nums[i - 1]}" if i - start > 1 else f"{nums[start]}")
                start = i
            prev = i

        return res