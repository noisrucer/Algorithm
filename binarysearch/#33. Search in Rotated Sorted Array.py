'''Method1
TC: O(logn)
SC: O(1)
'''
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, h = 0, n - 1

        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                return m
            
            if nums[m] > nums[h]:
                if nums[l] <= target < nums[m]:
                    h = m - 1
                else:
                    l = m + 1
            elif nums[m] < nums[l]:
                if nums[m] < target <= nums[h]:
                    l = m + 1
                else:
                    h = m - 1
            else:
                if target < nums[m]:
                    h = m - 1
                else:
                    l = m + 1
        
        return -1


'''Method2
TC: O(logn)
SC: O(1)
'''
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, h = 0, n - 1

        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                return m
            elif nums[m] > target:
                if nums[m] < nums[h]:
                    h = m - 1
                else: # nums[m] > nums[h], 
                    if target >= nums[l]:
                        h = m - 1
                    else:
                        l = m + 1
            else: # nums[m] < target
                if nums[m] > nums[l]:
                    l = m + 1
                else: # nums[m] < nums[l]
                    if target <= nums[h]:
                        l = m + 1
                    else:
                        h = m - 1

        return -1