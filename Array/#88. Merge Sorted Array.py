'''
TC: O(n + m)
SC: O(1)
'''

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j, p = m - 1, n - 1, m + n - 1
        while j >= 0: # If b is completely consumed, just leave A as it is cuz it's already sorted
            if i >= 0 and nums1[i] >= nums2[j]:
                nums1[p] = nums1[i]
                i -= 1
            else:
                nums1[p] = nums2[j]
                j -= 1
            p -= 1

