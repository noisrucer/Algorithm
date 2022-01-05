class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Q) Why is this question considered as a "Maximum Subarray" question?
        n = len(prices)
        
        # cur_max, glob_max initialization
        glob_max = cur_max = -1
    
        for i in range(1, n):
            diff = prices[i] - prices[i-1]
            cur_max = max(diff, cur_max + diff)
            glob_max = max(glob_max, cur_max)
        
        return glob_max if glob_max is not -1 else 0
            