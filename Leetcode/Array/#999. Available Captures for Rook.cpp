class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n =8;
        int x,y;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='R'){
                    x=i; y=j; break;
                }
            }
        }
        int i=x, j=y;
        int cnt=0;
        int l=j-1,r=j+1,u=i-1,d=i+1;
        while(l>=0 || u>=0 || r<n || d<n){
            if(l>=0 && board[i][l]=='B') l=-1;
            else if(l>=0 && board[i][l]=='p') {cnt++; l=-1; }
            
            if(r<n && board[i][r]=='B') r=n;
            else if(r<n && board[i][r]=='p'){cnt++; r=n; }
            
            if(u>=0 && board[u][j]=='B') u=-1;
            else if(u>=0 && board[u][j]=='p') {cnt++; u=-1; }
            
            if(d<n && board[d][j]=='B') d=n;
            else if(d<n && board[d][j]=='p') {cnt++;d=n;}
            l--;r++;u--;d++;
        }
        return cnt;
        
    }
};