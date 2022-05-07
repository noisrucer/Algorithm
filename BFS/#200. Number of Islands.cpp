//DFS
class Solution {
public:
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int n,m;
    
    void DFS(vector<vector<char>>&grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1') return;
        grid[i][j]='2';
        
        for(int dir=0; dir<4; dir++){
            DFS(grid,i+dx[dir],j+dy[dir]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt=0;
       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='0' || grid[i][j]=='2') continue;
                DFS(grid,i,j);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//BFS
lass Solution {
public:
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    #define X first
    #define Y second
    int n,m;
    
    void BFS(vector<vector<char>>&grid, int i, int j){
         queue<pair<int,int>>Q;
        Q.push({i,j});
        grid[i][j]='2';
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(grid[nx][ny]=='2' || grid[nx][ny]=='0') continue;
                Q.push({nx,ny});
               grid[nx][ny]='2';
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt=0;
       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='0' || grid[i][j]=='2') continue;
                BFS(grid,i,j);
                cnt++;
                
            }
        }
        
        return cnt;
    }
};