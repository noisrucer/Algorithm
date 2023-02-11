class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        self.m, self.n = len(image), len(image[0])
        self.dx = [1, 0, -1, 0]
        self.dy = [0, 1, 0, -1]
        self.start_color = image[sr][sc]
        self.bfs(image, color, sr, sc)
        return image

        
    def bfs(self, image, color, i, j):
        Q = deque()
        Q.append((i, j))
        image[i][j] = color

        while Q:
            curr = Q.popleft()
            for direction in range(4):
                nx = curr[0] + self.dx[direction]
                ny = curr[1] + self.dy[direction]

                if nx < 0 or ny < 0 or nx >= self.m or ny >= self.n:
                    continue
                if image[nx][ny] != self.start_color or image[nx][ny] == color:
                    continue

                Q.append((nx, ny))
                image[nx][ny] = color