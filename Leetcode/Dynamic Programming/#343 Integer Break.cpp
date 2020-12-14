class Solution {
public:
    int topdown(int n,vector<int>dp){
        if(n<=2) return 1;
        if(dp[n]) return dp[n];
        for(int i=1; i<=n/2; i++){
            dp[n]=max({dp[n],i*(n-i),i*topdown(n-i,dp)});
        }
        return dp[n];
    }
    int integerBreak(int n) {
       vector<int>dp(n+1,0);
        dp[1]=0;
        dp[2]=1;
        for(int i=3; i<=n; i++){
            for(int j=1; j<=i/2; j++){
                dp[i]=max({dp[i],j*(i-j),j*dp[i-j]});
            }
        }
        
        return dp[n];
    }
};