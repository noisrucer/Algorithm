// #1 Fast
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, duplicate = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    if(i!=0 && grid[i-1][j] == 1) duplicate++;
                    if(j!=0 && grid[i][j-1] == 1) duplicate++;
                }
            }
        }
        
        return 4*cnt - 2*duplicate;
    }
};

// #2 Solution - slow BFS
class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    #define X first
    #define Y second
    int n, m;
    vector<vector<int>>spotted;
    
    void BFS(vector<vector<int>>&grid, vector<vector<int>>&visited, int i, int j, int &perimeter){
        queue<pair<int,int>>Q;
        Q.push({i,j});
        visited[i][j] = true;
        int neighbor = 0;
        
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            spotted[cur.X][cur.Y] = true;
            neighbor = 0;
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if(nx<0 || ny<0 || nx >= n || ny >= m) continue;
                if(spotted[nx][ny]) neighbor++;
                if(visited[nx][ny] || grid[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                Q.push({nx,ny});
            }
            
            perimeter -= neighbor;
            perimeter += (4-neighbor);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        int perimeter = 0;
        
        vector<vector<int>>visited(n,vector<int>(m,false));
        spotted.resize(n,vector<int>(m,false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] || grid[i][j] == 0) continue;
                BFS(grid,visited,i,j,perimeter);
            }
        }
        
        return perimeter;
    }
};