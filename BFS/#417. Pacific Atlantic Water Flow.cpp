class Solution {
public:
    vector<vector<bool>>pacific, atlantic;
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    #define X first
    #define Y second
    vector<vector<int>>res;
    
    void BFS_pacific(vector<vector<int>>&matrix, int i, int j){
        queue<pair<int,int>>Q;
        Q.push({i,j});
        pacific[i][j]=true;
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(pacific[nx][ny] || matrix[nx][ny] < matrix[cur.X][cur.Y]) continue;
                
                Q.push({nx,ny});
                pacific[nx][ny]=true;
            }
        }
    }
    
    void BFS_atlantic(vector<vector<int>>&matrix, int i, int j){
        queue<pair<int,int>>Q;
        Q.push({i,j});
        
        atlantic[i][j]=true;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            
            if(pacific[cur.X][cur.Y]) res.push_back({cur.X,cur.Y});
            
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(atlantic[nx][ny] || matrix[nx][ny] < matrix[cur.X][cur.Y]) continue;
                
                Q.push({nx,ny});
                atlantic[nx][ny]=true;
            }
        }
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        n=matrix.size(); if(!n) return {};
        m=matrix[0].size();
        pacific.resize(n,vector<bool>(m,false));
        atlantic.resize(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            if(pacific[i][0]) continue;
            BFS_pacific(matrix,i,0);
        }
        
        for(int j=0; j<m; j++){
            if(pacific[0][j]) continue;
            BFS_pacific(matrix,0,j);
        }
        
        for(int i=0; i<n; i++){
            if(atlantic[i][m-1]) continue;
            BFS_atlantic(matrix,i,m-1);
        }
        
        for(int j=0; j<m; j++){
            if(atlantic[n-1][j]) continue;
            BFS_atlantic(matrix,n-1,j);
        }
        
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
//             }
//         }
        
        return res;
        
    }
};