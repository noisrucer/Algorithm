class Solution {
public:
    #define X first
    #define Y second
    int dx[4]= {1,0,-1,0};
    int dy[4]= {0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int max_area = INT_MIN;
        queue<pair<int,int>>Q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0 || vis[i][j]) continue;
                int current_area = 0;
                Q.push({i,j});
                vis[i][j]=true;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    current_area++;
                    for(int dir =0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(grid[nx][ny]==0 || vis[nx][ny]) continue;
                        Q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                } max_area = max (max_area,current_area);
            }
        }
        if(max_area==INT_MIN) return 0;
        return max_area;
    }
};