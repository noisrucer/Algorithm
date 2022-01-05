class Solution:
    def tribonacci(self, n: int) -> int:
        cache = [-1 for x in range(n+1)] # Cache Initialization
        
        def topdown(k):
            # Base Cases
            if k==0:
                return 0
            if k==1:
                return 1
            if k==2:
                return 1
            
            # Memoization
            if cache[k] is not -1:
                return cache[k]
            
            # General Case
            cache[k] = topdown(k-3) + topdown(k-2) + topdown(k-1)
            return cache[k]
        
        return topdown(n)
        