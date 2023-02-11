'''
TC: O(n)
SC: O(n)
'''

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        history = set()
        n = len(nums)
        for i in range(n):
            if i > k:
                history.remove(nums[i - k - 1])
            if nums[i] in history:
                return True
            history.add(nums[i])

        return False