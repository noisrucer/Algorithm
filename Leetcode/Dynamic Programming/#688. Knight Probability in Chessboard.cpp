class Solution {
public:
   
    int dx[8]={2,2,-2,-2,1,1,-1,-1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};
    double dp[26][26][101];
    double knightProbability(int N, int K, int r, int c) {
        if(r<0 || c<0 || r>=N || c>=N) return 0;
        if(K==0) return 1;
        if(dp[r][c][K]) return dp[r][c][K];
        double total=0;
        
        for(int dir=0; dir<8; dir++)
            total+=knightProbability(N,K-1,r+dx[dir],c+dy[dir]);
        
       dp[r][c][K]=total/8; //
       return dp[r][c][K];
          
    }
};