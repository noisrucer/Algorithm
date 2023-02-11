'''
TC: O(n) for finding sum 
SC: O(1)
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return len(nums) * (len(nums) + 1) // 2 - sum(nums)
