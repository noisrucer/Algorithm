// TOPDOWN
vector<vector<vector<int>>>dp;
int n;

int topdown(vector<string>& strings, int i, int p, int q){
    if(i<0) return 0;
    if(dp[i][p][q]!=INT_MIN) return dp[i][p][q];
    int num_A = count(strings[i].begin(), strings[i].end(),'A');
    int len = strings[i].length();

    if(p>=num_A && q>=len-num_A){
        dp[i][p][q] = max(1+topdown(strings,i-1,p-num_A,q-(len-num_A)), topdown(strings,i-1,p,q));
    }else{
        dp[i][p][q] = topdown(strings,i-1,p,q);
    }
    return dp[i][p][q];
}

int solve(vector<string>& strings, int a, int b) {
    n = strings.size();
    dp={};
    dp.resize(n,vector<vector<int>>(a+1,vector<int>(b+1,INT_MIN)));
    return topdown(strings,n-1,a,b);
}

//BOTTOM UP

//Bottom Up
int solve(vector<string>& strings, int a, int b) {
    int n = strings.size(), countA, len;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(a+1,vector<int>(b+1,0)));
    for(int i=1; i<=n; i++){
        for(int p=0; p<=a; p++){
            for(int q=0; q<=b; q++){
                 countA = count(strings[i-1].begin(), strings[i-1].end(),'A');
                 len = strings[i-1].length();
                 if(p>=countA && q>=len-countA) dp[i][p][q] = max(1 + dp[i-1][p-countA][q-(len-countA)], dp[i-1][p][q]);
                 else dp[i][p][q] = dp[i-1][p][q];
            }
        }
    }

    return dp[n][a][b];
}