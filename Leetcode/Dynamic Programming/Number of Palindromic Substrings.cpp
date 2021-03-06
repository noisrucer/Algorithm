int solve(string s) {
    int n = s.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int res = n;
    for(int i=0; i<n; i++){
        dp[i][i] = true;
    }
    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i + len - 1;
            // cout<<i<<" "<<j<<endl;
            if(len==2){
                if(s[i]==s[j]){
                    dp[i][j] = true;
                    res++;
                }
            }else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    res++;
                }
            }

        }
    }
    return res;
    
}