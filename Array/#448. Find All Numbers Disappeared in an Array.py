'''
TC: O(n)
SC: O(1)
'''

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res = []
        for e in nums:
            e = abs(e)
            nums[e - 1] = -1 * abs(nums[e - 1])

        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i + 1)

        return res