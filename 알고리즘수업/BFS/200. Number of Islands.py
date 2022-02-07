class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #############################DEFAULT####################################
        self.m, self.n = len(grid), len(grid[0])
        self.dx = [1, 0, -1, 0]
        self.dy = [0, 1, 0, -1]
        self.grid = grid
        self.visited = [[False for _ in range(self.n)] for _ in range(self.m)]
        ########################################################################
        num_islands = 0 # CHANGE
        
        ################################DEFAULT#######################################
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j]=="1" and (not self.visited[i][j]):
                    num_islands += 1 # CHANGE
                    self.BFS(i, j) # CHANGE
        #############################################################################         
        return num_islands
    
    # [1] BFS
    ##################################################################################
    def BFS(self, i, j):
        Q = []
        Q.append((i,j)) # starting point # DEFAULT 
        self.visited[i][j] = True # DEFAULT
        
        while len(Q): # DEFAULT
            cur = Q[0] # DEFAULT (현재 좌표)
            Q.pop(0) # DEFAULT

            for d in range(4):
                nx = cur[0] + self.dx[d] # DEFAULT
                ny = cur[1] + self.dy[d] # DEFAULT
                
                if nx<0 or ny<0 or nx>=self.m or ny>=self.n: # DEFAULT
                    continue
                if self.grid[nx][ny]=='0' or self.visited[nx][ny]: #DEFAULT
                    continue
                
                self.visited[nx][ny] = True #DEFAULT
                Q.append((nx,ny)) #DEFAULT
                
        return None
    ####################################################################################
    # [2] DFS
    def DFS(self, i, j):
        if i<0 or j<0 or i>=self.m or j>=self.n:
            return None
        if self.grid[i][j] == '0' or self.visited[i][j]:
            return None
        
        self.visited[i][j] = True
        
        for d in range(4):
            nx = i + self.dx[d]
            ny = j + self.dy[d]
            
            self.DFS(nx, ny)
        
        return None
        