class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return next(iter(set(edges[0]) & set(edges[1])))
        