class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [-1] * (n + 1)
        
        def topdown(n):
            if n <= 1:
                return False
            if dp[n] is not -1:
                return dp[n]
            
            for i in range(1, n):
                if n % i == 0 and not(topdown(n-i)):
                    dp[n] = True
                    return dp[n]
                dp[n] = False
                return dp[n]
            
        
        return topdown(n)
        
        
        
        
        