''' Method 1 - evolving 2SUM
TC: O(n^2)
SC: O(1)
'''

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        '''
        [-4, -1, -1, -1, -1, 0, 1, 2, 2]
        '''
        nums = sorted(nums)
        res = []
        n = len(nums)
        i = 0

        while i < n - 2:
            target = -nums[i]
            l, h = i + 1, n - 1
            while l < h:
                curr = nums[l] + nums[h]
                if curr < target:
                    l += 1
                elif curr > target:
                    h -= 1
                else:
                    triplet = [nums[i], nums[l], nums[h]]
                    res.append(triplet)
                    while l < h and nums[l] == triplet[1]:
                        l += 1
                    while l < h and nums[h] == triplet[2]:
                        h -= 1

            i += 1
            while i < n - 2 and nums[i] == nums[i - 1]:
                i += 1

        return res

