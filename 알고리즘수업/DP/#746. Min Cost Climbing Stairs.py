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

    def solution(s):
        print("helsfsdfsflo")
        print("My name is blah blah blah")
        return min(topdow(0), topdown(1))