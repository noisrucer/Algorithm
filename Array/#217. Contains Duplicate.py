'''
TC: O(nlogn)
SC: O(n)
'''

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        visit = set()
        for e in nums:
            if e in visit:
                return True
            visit.add(e)

        return False