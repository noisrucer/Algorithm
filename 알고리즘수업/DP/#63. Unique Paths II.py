class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        cache = [[-1 for _ in range(n)] for _ in range(m)]
        
        def topdown(i, j):
            if i<0 or j<0 or obstacleGrid[i][j] == 1: # Just one more base-case! And this is very obvious!
                return 0
            if i==0 and j==0:
                return 1
            
            if cache[i][j] != -1:
                return cache[i][j]
            
            cache[i][j] = topdown(i-1,j) + topdown(i,j-1)
            return cache[i][j]
        
        return topdown(m-1,n-1)