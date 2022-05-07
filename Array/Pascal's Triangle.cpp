//1D space complexity O(n^2)
vector<int> solve(int n) {
    vector<int>res;
    res.push_back(1);
    while(n--){
        for(int i=res.size()-1; i>=1; i--){
            res[i] += res[i-1];
        }
        res.push_back(1);
    }
    return res;
}


//DP solution
vector<vector<int>>dp;
int helper(int i, int j){
    if(i==0 && j==0) return 1;
    if(j<0 || j>i || i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = helper(i-1,j-1) + helper(i-1,j);
}
vector<int> solve(int n) {
    dp.clear();
    dp.resize(n+1,vector<int>(n+1,-1));
    vector<int>res(n+1);
    for(int i=0; i<=n; i++){
        res[i] = helper(n,i);
    }
    return res;
}

