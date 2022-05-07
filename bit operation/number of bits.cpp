int solve(int n) {
    int cnt=0;
    while(n){
        if(n & 1) cnt++;
        n = n>>1;
    }
    return cnt; 
}
