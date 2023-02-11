# Time Complexity: O(n)
# Space Complexity: O(1) in-place

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        idx = 0 # tracking last element of result list

        for e in nums:
            if nums[idx] == e: # very first element will always be skipped as it must be included as the first el in the result list
                continue
            idx += 1
            nums[idx] = e

        return idx + 1