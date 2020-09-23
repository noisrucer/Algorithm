class Solution {
public:
    vector<vector<char>>grid;
    string target;
    bool vis[201][201]{};
    int n,m;
    
    bool back(int i, int j, int k){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(vis[i][j]) return false;
        if(grid[i][j]!=target[k]) return false;
        if(k==target.length()-1) return true;
        vis[i][j]=true;
        bool trueornot = back(i+1,j,k+1) ||back(i,j+1,k+1)||back(i-1,j,k+1)||back(i,j-1,k+1);
        vis[i][j]=false; //YOU CANNOT JUST RETURN ABOVE otherwise it will jump this current sentence.
        return trueornot;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0) return false;
        grid=board;
        target = word;
        n= board.size();
        m = board[0].size();
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(board[i][j]!=word[0]) continue;
                if(back(i,j,0)) return true;
                
            }
        }
        return false;
    }
};