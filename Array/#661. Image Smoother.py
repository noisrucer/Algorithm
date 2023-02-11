class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                sum_, cnt = 0, 0
                for nx in range(max(0, i - 1), min(m, i + 2)):
                    for ny in range(max(0, j - 1), min(n, j + 2)):
                        sum_ += img[nx][ny]
                        cnt += 1

                res[i][j] = sum_ // cnt
        return res