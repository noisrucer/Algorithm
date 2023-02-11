# 1) Reframe question: Given n steps, return distinct # ways to reach the top by taking 1 or 2 steps only
# 2) Generalization: f(i) = # ways to reach ith step by taking 1 or 2 steps only
# 3) Base case: f(1) = 1, f(2) = 2
# 4) General case: f(i) = f(i - 1) + f(i - 2)

'''
Method 1 - Topdown
Time Complexity: O(n)
Space Complexity: O(2n) = O(n), one for dp array, and for stack frames
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        self.dp = [-1 for _ in range(n + 1)]
        return self.topdown(n)

    def topdown(self, i):
        if i == 0:
            return 1
        if i == 1:
            return 1

        if self.dp[i] != -1:
            return self.dp[i]

        self.dp[i] = self.topdown(i - 1) + self.topdown(i - 2)
        return self.dp[i]
    
    
'''
Method 1 - Bottom up
Time Complexity: O(n)
Space Complexity: O(n)
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [-1 for _ in range(n + 1)]
        dp[0] = 1
        dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        return dp[n]