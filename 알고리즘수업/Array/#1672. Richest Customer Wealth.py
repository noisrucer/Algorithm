class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maxSum = 0
        for i in range(len(accounts)):
            maxSum = max(maxSum, sum(accounts[i]))
        return maxSum
        