'''
TC: O(n)
SC: O(n)
'''

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        stk, res = [], []
        stk.append(nums2[0])
        nge = dict()
        nge[nums2[0]] = -1

        for e in nums2[1:]:
            nge[e] = -1
            while stk and e > stk[-1]:
                nge[stk[-1]] = e
                stk.pop()

            stk.append(e)

        for e in nums1:
            res.append(nge[e])

        return res
        