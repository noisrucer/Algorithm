class Solution {
public:

    vector<int>dp;
    int topdown(int n){
      if(n==1) return 0;
        if(dp[n]!=INT_MAX) return dp[n];
        for(int i=1; i<n; i++){
            if(n%i==0){
                dp[n]=min(dp[n],topdown(i)+n/i);
            }
        }
        return dp[n];
        
    }
    int minSteps(int n) {
        if(n==1) return 0;
        dp = vector<int>(n+1,INT_MAX);
        return topdown(n);
        
    }
};