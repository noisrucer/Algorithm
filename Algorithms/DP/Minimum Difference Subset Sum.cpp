int Solution::solve(vector<int> &A) {
    int n = A.size();
    int sum = accumulate(A.begin(), A.end(), 0);
    
	//Initialize dp table
   vector<vector<int>>dp(n+1, vector<int>(sum+1,false));
   for(int i = 0; i <= n; i++){ // we can always make 0 by doing nothing!
       dp[i][0] = true;
   }
   
	//Proceed normal subset sum DP
   for(int i=1; i<=n; i++){
       for(int j=1; j<=sum; j++){
           if(A[i-1]>j) dp[i][j]=dp[i-1][j];
           else{
               dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
           }
       }
   }
   
	//Using ALL elements, look at all the possible subset sums
	//Here, we're focusing on S1 only since S2 is simply SUM-S1.
	//since S1<=S2, find in interval [0,sum/2] only because in (sum/2,sum],
	//That's S2 since it's more than half => greater than S1.
	//Using all subsets, compare min_diff. Here, remember diff = sum - 2 * S1 !
   int min_diff = INT_MAX;
   for(int i=0; i<=sum/2; i++){
      if(!dp[n][i]) continue;
      min_diff = min(min_diff,sum-2*i);
   }
   
   return min_diff;
}