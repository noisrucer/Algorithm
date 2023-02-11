''' Method 1
TC: O(n)
SC: O(1)
'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1
        

''' Method 2
TC: O(n)
SC: O(1)
'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        num_zeros = 0
        i = 0
        for e in nums:
            if e == 0:
                num_zeros += 1
            else:
                nums[i] = e
                i += 1
        nums[n - num_zeros:] = [0] * num_zeros
