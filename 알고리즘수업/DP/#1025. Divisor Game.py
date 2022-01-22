class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [-1] * (n + 1)
        
        def topdown(n):
            # n <= 1, LOSE
            if n <= 1:
                return False
            
            # Memoization
            if dp[n] is not -1:
                return dp[n]
            
            # Simulate the given question
            for i in range(1, n): # condition 1
                if n % i == 0: # condition 2
                    if not(topdown(n-i)): # If the other player loses
                        dp[n] = True # We win!
                        return dp[n]
            
            dp[n] = False
            return dp[n]
        
        return topdown(n)
        
    1) 0 < x < 3, n % x == 0
    2) 창진 한테 n - x로 게임을 시작해라!
    
    * 더이상 move X -> LOSE!
    
    (PROBLEM): GOAL
    1) f(n) = "어떤" 플레이어가 n을 가지고 무조건 이길 수가 "있는지"
    2) General Case: f(n) = !f(n-x) 
        
        어떤 "state"
        
        
        Alice
        f(n) = f(n-x) 
    
    
    
        
        
        
        
        