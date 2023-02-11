'''
TC: O(n)
SC: O(1)
'''

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Kadane's Algorithm
        n = len(prices)

        cur_max, glob_max = 0, 0
        for i in range(1, n):
            diff = prices[i] - prices[i - 1]
            cur_max = max(cur_max + diff, diff)
            glob_max = max(cur_max, glob_max)

        return glob_max