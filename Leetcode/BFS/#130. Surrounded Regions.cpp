class Solution {
public:
    #define X first
    #define Y second
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int n,m;
    vector<vector<bool>>visit;
    
    void BFS(vector<vector<char>>&board, int i, int j, bool firstrow){
        queue<pair<int,int>>Q;
        Q.push({i,j});
        visit[i][j]=true;
        if(!firstrow) board[i][j]='X';
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(visit[nx][ny] || board[nx][ny]=='X') continue;
                visit[nx][ny]=true;
                Q.push({nx,ny});
                if(!firstrow) board[nx][ny]='X';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n=board.size(); if(n==0) return;
        m=board[0].size();
        visit.resize(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i!=0 && i!=n-1 && j!=0 && j!=m-1)||(board[i][j]=='X' || visit[i][j])) continue;
                BFS(board,i,j,true);
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(board[i][j]=='X' || visit[i][j]) continue;
                BFS(board,i,j,false);
            }
        }
    }
};

