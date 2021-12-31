class Solution:
    def climbStairs(self, n: int) -> int:
        cache = [-1] * (n + 1)
        
        def topdown(i):
            if i <= 1:
                return 1
            if cache[i] is not -1:
                return cache[i]
            
            cache[i] = topdown(i-1) + topdown(i-2)
            return cache[i]
        
        return topdown(n)
        