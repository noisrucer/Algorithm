vector<long long>dp;
#define MODE 1000000007
long long bst(int x){
    if(x<=1) return 1;
    if(dp[x] != -1) return dp[x];

    long long res = 0;

    for(int i=0; i<x; i++){
        res += (bst(i) * bst(x-1-i) % MODE);
    }
 

    return dp[x] = res % 1000000007;
}

int solve(int n) {
    if(n==0) return 1;
    dp.clear();
    dp.resize(n+1,-1);
    return bst(n)%MODE;
}