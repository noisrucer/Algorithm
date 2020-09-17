class Solution {
public:
    int dp[50]{};
    int climbStairs(int n) {
     if(n==0) return 1;
     if(n==1) return 1;
        if(dp[n]) return dp[n];
        dp[n]=climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
        
    }
};