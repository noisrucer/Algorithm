class Solution {
public:
    vector<vector<int>>dp;
   
    int helper(int l, int r){
        if(l>=r) return 0;
        if(dp[l][r]!=INT_MAX) return dp[l][r];
        for(int m=(l+r)/2; m<r; m++){
            dp[l][r] = min(dp[l][r], m + max(helper(l,m-1),helper(m+1,r)) );
        }
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n+1,vector<int>(n+1, INT_MAX));
        return helper(1,n);
    }
};
/*
7+9+
l         r   l    r
1 2 3 4 5 6 7 8 9 10
    
dp[l][r] => l,r에서 쓸수있는 max amount of money

if(l==r) return 0;
for(int i=1; i<=n; i++){
m = i;
dp[l][r] =min(dp[l][r], m  +  max(dp[l][m-1],dp[m+1][r]))  
}
int m = l+(r-l)/2;
for()
dp[l][r]=  m  +  max(dp[l][m-1],dp[m+1][r])
*/