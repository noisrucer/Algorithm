vector<int> solve(int n) {
    vector<int>prime(n+1,false);
    if(n==1) return {};
    vector<int>res;
    for(int i=2; i<=n; i++){
        if(prime[i]) continue;
        res.push_back(i);
        for(int j=1; i*j<=n; j++){
            prime[i*j] = true;
        }
    }
    return res;
}