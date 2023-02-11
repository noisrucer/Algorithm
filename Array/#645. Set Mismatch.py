class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dup = None
        for e in nums:
            if nums[abs(e) - 1] > 0:
                nums[abs(e) - 1] *= -1
            else:
                dup = abs(e)
        
        for i in range(n):
            if nums[i] > 0:
                return [dup, i + 1]

        return []