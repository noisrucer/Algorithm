# Time Complexity: O(nlogn)
# Space Complexity: O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # arr[i] + arr[j] = target
        # Assume we know arr[i], then we must find arr[j] = target - arr[i]
        dct = dict() # {val: idx}
        for i, val in enumerate(nums):
            if target - val in dct:
                return [dct[target - val], i]
            dct[val] = i

        return None # Guaranteed there exists a solution