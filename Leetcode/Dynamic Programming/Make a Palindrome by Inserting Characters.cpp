vector<vector<int>>dp;
int n;
int topdown(string &s, int i, int j){
   if(i>=j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];

   if(s[i]==s[j]) dp[i][j] = topdown(s,i+1,j-1);
   else dp[i][j] = min({1+topdown(s,i+1,j),1+topdown(s,i,j-1), 2+topdown(s,i+1,j-1)});

   return dp[i][j];
}

int solve(string s) {
   n = s.length();
   dp.clear();
   dp.resize(n,vector<int>(n,-1));
   return topdown(s,0,n-1);
    
}