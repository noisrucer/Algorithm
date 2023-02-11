'''
TC: O(n)
SC: O(n)
'''

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        visit = set()
        res = []
        i, j = 0, 0
        for e in nums1:
            visit.add(e)
        for e in nums2:
            if e in visit:
                res.append(e)
                visit.remove(e)

        return res