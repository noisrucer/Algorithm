int solve(int n, int e, int o, int t) {
    double amount = n;
    int res = 0, cnt = 0;
    while(amount < t){
        if(cnt%2==0) amount += amount*(e/100.0);
        else amount += amount*(o/100.0);
        cnt++;
        res++;
    }
    return res;
}