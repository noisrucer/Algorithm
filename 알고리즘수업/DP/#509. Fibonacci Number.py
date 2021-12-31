'''
1) 문제정의: Find the nth fibonacci number
2) 알고리즘: Dynamic Programming / Recursion
3) 자료구조: Array for DP
4) 해결전략: 
   1) Generalization - fibo(n) = nth fibonacci number
   2) Define the "Recurrence Relation" -> [IMPORTANT] 1) 과정을 "그대로" 점화식으로 변경.
      - General Case / Base Case
      - Hardest step
      - f(n) = nth fibonacci number
      - f(n) = f(n-1) + f(n-2)
   3) Define Topdown function -> [IMPORTANT]점화식을 "그대로" return함
      - int topdown(int n) -> nth fibonacci number을 리턴함
   4) Memoization(DP Step)
   5) DONE!

<TIPS>
재귀/DP 문제의 경우 위의 해결전략을 따르는게 엄청 중요함. 해결전략 그대로 따라가면 바로 풀리는 문제들도 상당히 많음.
'''

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
            
        