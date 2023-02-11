'''
TC: O(n)
SC: O(n)
'''

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        res = 0

        for e in nums:
            freq[e] += 1
            res = max(
                res,
                (freq[e] + freq[e - 1]) * (freq[e - 1] != 0),
                (freq[e] + freq[e + 1]) * (freq[e + 1] != 0)
            )
        return res
