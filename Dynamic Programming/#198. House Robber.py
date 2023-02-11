''' Top-down
f(i): max money from index 0 ~ i

[Base case]
f(0) = nums[0]
f(1) = nums[1]

[General case]
f(i) = max(nums[i] + f(i - 2), f(i - 1))
'''
        
class Solution:
    def rob(self, nums: List[int]) -> int:
        self.n = len(nums)
        self.dp = [-1 for _ in range(self.n)]
        return self.topdown(nums, self.n - 1)


    def topdown(self, nums, i):
        if i == 0:
            return nums[0]
        if i == 1:
            return max(nums[0], nums[1]) 

        if self.dp[i] != -1:
            return self.dp[i]

        self.dp[i] = max(nums[i] + self.topdown(nums, i - 2), self.topdown(nums, i - 1))
        return self.dp[i]
    
''' Bottom-up - Optimized
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        prev1, prev2 = 0, 0
        for e in nums:
            curr = max(e + prev1, prev2)
            prev1 = prev2
            prev2 = curr
        return prev2
        
''' Bottom-up
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [-1 for _ in range(n)]
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])

        return max(dp[n - 1], dp[n - 2])