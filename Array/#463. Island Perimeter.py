'''
TC: O(mn)
SC: O(1)
'''
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        box, tangent = 0, 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue

                box += 1
                if i > 0 and grid[i - 1][j] == 1:
                    tangent += 1
                if j > 0 and grid[i][j - 1] == 1:
                    tangent += 1

                
        return 4 * box - 2 * tangent

