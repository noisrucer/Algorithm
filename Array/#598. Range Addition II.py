class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        min_x, min_y = m, n
        for x, y in ops:
            min_x, min_y = min(min_x, x), min(min_y, y)
        return min_x * min_y