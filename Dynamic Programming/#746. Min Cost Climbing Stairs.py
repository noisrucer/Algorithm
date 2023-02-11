# Return the minimum cost to reach the top of the floor, given cost array
# f(i) = 0 부터 출발해서 i번째 계단 the minimum cost to reach, given cost array

# f(i) = cost[i] + min(f(i-1), f(i-2))

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [-1] * n
        # f(i) = min cost from 0 ~ i, but must step on i
        # f(n) = f(n-1) + f(n-2)
        
        def f(i):
            if i < 0: 
                return 0
            if dp[i] is not -1:
                return dp[i]
            dp[i] = cost[i] + min(f(i-1), f(i-2))
            return dp[i]
        
        return min(f(n-1), f(n-2))