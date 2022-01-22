class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [-1] * n
        
        def topdown(i: int):
            if i >= n:
                return 0
            if dp[i] is not -1:
                return dp[i]
            dp[i] = cost[i] + min(topdown(i+1), topdown(i+2))
            return dp[i]
        
        return min(topdown(0), topdown(1))
        
        
        
        # 
# // cost.size() = 
# // 0 ~ n-1
# // dp[i] = i에서 n으로 가는데 필요한 minimum cost
# // dp[i] = cost[i] + min(dp[i+1], dp[i+2]);

# // (base case)
# // dp[i >= n] return 0;
        
        