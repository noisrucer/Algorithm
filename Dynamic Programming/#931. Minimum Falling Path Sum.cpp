class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int minPath(int i, int j, vector<vector<int>>&A){
        if(i==n-1) return A[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        dp[i][j]=min(dp[i][j],A[i][j]+minPath(i+1,j,A));
        if(j-1>=0)dp[i][j]=min(dp[i][j],A[i][j]+minPath(i+1,j-1,A));
        if(j+1<m) dp[i][j]=min(dp[i][j],A[i][j]+minPath(i+1,j+1,A));
        
        return dp[i][j];
        }
    int minFallingPathSum(vector<vector<int>>& A) {
        n=A.size();
        m=A[0].size();
        dp.resize(n,vector<int>(m,INT_MAX));
        int res=INT_MAX;
        for(int i=0; i<m; i++)
            res=min(res,minPath(0,i,A));
        
        return res;
    }
};