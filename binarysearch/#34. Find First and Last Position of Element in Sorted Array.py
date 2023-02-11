'''Method 1
TC: O(logn)
SC: O(1)
'''
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = [-1, -1]
        n = len(nums)
        if n == 0:
            return res

        # Find leftmost target
        l, h = 0, n - 1
        while l < h: # notice it's not <=
            m = (l + h) // 2
            if nums[m] < target:
                l = m + 1
            else:
                h = m
                
        if nums[l] != target:
            return res
        res[0] = l

        h = n - 1 # don't need to set l = 0 again.
        # Find rightmost target
        while l < h:
            m = (l + h) // 2 + 1 # trick to avoid infinite loop. Consider [8, 8] for [8, 9]] 
            if nums[m] > target:
                h = m - 1
            else: # nums[m] <= target
                l = m
        res[1] = h
        return res
                


'''Method 2
TC: O(logn)
SC: O(1)
'''
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # STEP 1) First find leftmost target
        n = len(nums)
        l, h = 0, n - 1
        res = [-1, -1]
        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                if m == 0:
                    res[0] = 0
                    break
                if nums[m] == nums[m - 1]:
                    h = m - 1
                else:
                    res[0] = m
                    break
            elif target < nums[m]:
                h = m - 1
            else:
                l = m + 1

        # Check if target exists, return -1 if not
        if res[0] == -1:
            return [-1, -1]
        
        # STEP 2) Find rightmost target
        l, h = res[0], n - 1 # start from leftmost target index
        while l <= h:
            m = (l + h) // 2
            if nums[m] == target:
                if m == n - 1:
                    res[1] = m
                    break
                if nums[m] == nums[m + 1]:
                    l = m + 1
                else:
                    res[1] = m
                    break
            elif target < nums[m]:
                h = m - 1
            else:
                l = m + 1

        return res
