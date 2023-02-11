'''
TC: O(n)
SC: O(1)

[Description]
Area = (j - i) * min(height[i], height[j])
If height[i] < height[j], we must move i to the right.
If height[i] > height[j], we must move j to the left
If height[i] == height[j], we can move either i or j
'''

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        i, j = 0, n - 1
        res = -1
        while i < j:
            res = max(res, (j - i) * min(height[i], height[j]))
            if height[i] >= height[j]:
                j -= 1
            else:
                i += 1

        return res
            
        