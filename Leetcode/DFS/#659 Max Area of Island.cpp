class Solution {
public:
    #define X first
    #define Y second
    int dx[4]= {1,0,-1,0};
    int dy[4]= {0,1,0,-1};
    int n,m;
    vector<vector<bool>>vis;
    int dfs(vector<vector<int>>& grid, int nx, int ny){
        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==0 || vis[nx][ny]) return 0;
        vis[nx][ny]=true;
        return 1+dfs(grid,nx+1,ny)+dfs(grid,nx,ny+1)+dfs(grid,nx-1,ny)+dfs(grid,nx,ny-1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        n=grid.size();
        m=grid[0].size();
        vis = vector<vector<bool>>(n,vector<bool>(m,0));
        int max_area = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0 || vis[i][j]) continue;
                max_area = max(max_area,dfs(grid,i,j));
            }
        }
        if(max_area==INT_MIN) return 0;
        return max_area;
      
    }
};