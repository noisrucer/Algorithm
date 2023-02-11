'''Method 1
TC: O(logn)
SC: O(1)
'''
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, h = 0, n - 1
        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                h = m - 1

        return l


'''Method 2
TC: O(logn)
SC: O(1)
'''
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, h = 0, n - 1
        while l <= h:
            m = (l + h) // 2
            sub_len = h - l + 1
            if nums[m] == target:
                return m
            elif nums[m] < target:
                if sub_len == 1:
                    return m + 1
                l = m + 1
            else:
                if sub_len == 2 or sub_len == 1:
                    return m
                h = m - 1

        return None
        