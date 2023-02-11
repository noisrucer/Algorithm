'''
TC: O(mn)
SC: O(1)
'''
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        res = [[None for _ in range(c)] for _ in range(r)]
        if r * c != m * n:
            return mat

        for i in range(m):
            for j in range(n):
                idx = i * n + j
                res[idx // c][idx % c] = mat[i][j]

        return res