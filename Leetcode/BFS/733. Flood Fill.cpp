class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    #define X first
    #define Y second
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        queue<pair<int,int>>Q;
        vector<vector<int>>visited(n,vector<int>(m,false));
        visited[sr][sc] = true;
        Q.push({sr,sc});
        int originalColor = image[sr][sc];
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            image[cur.X][cur.Y] = newColor;
            for(int dir = 0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(visited[nx][ny]) continue;
                if(image[nx][ny]!=originalColor) continue;
                
                Q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
        
        return image;
    }
};