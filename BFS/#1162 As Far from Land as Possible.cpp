#define X first
#define Y second

class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int n;
    int dist[101][101];    
   
    
    int maxDistance(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        n = grid.size();
        queue<pair<int,int>>Q;
        bool land=false, water=false;
        for(int i=0; i<101; i++) fill(dist[i],dist[i]+101,-1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    land=true;
                    Q.push({i,j});
                    dist[i][j]=0;
                    continue;
                }
                water=true;
            }
        }
        if(!water||!land) return -1;
        int mx=INT_MIN;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            mx = max(mx, dist[cur.X][cur.Y]);
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(dist[nx][ny]>=0) continue;
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
        }
        return mx;
        
     
    }
};