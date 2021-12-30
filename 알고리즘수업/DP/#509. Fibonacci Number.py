class Solution:
    def fib(self, n: int) -> int:
        cache = [-1] * (n + 1)
        
        def topdown(k):
            if k <= 1:
                return k
            if cache[k] is not -1:
                return cache[k]
            cache[k] = topdown(k-1) + topdown(k-2)
            return cache[k]
        
        return topdown(n)
            
        