'''Bottomup
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        return max(self.helper(nums, 0, n - 2), self.helper(nums, 1, n - 1))
        
    def helper(self, nums, start, end):
        prev1, prev2 = 0, 0
        for i in range(start, end + 1):
            curr = max(prev1 + nums[i], prev2)
            prev1 = prev2
            prev2 = curr
        return prev2


'''Topdown
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        self.dp = [[-1 for _ in range(2)] for _ in range(n)]
        return max(self.topdown(nums, n - 2, 0), nums[n - 1] + self.topdown(nums, n - 3, 1))


    def topdown(self, nums, i, j):
        if i < 0:
            return 0
        if i == 0:
            return nums[0] if j == 0 else 0

        if self.dp[i][j] != -1:
            return self.dp[i][j]

        self.dp[i][j] = max(nums[i] + self.topdown(nums, i - 2, j), self.topdown(nums, i - 1, j))
        return self.dp[i][j]

