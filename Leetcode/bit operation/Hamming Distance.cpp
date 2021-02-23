int solve(int x, int y) {
    int res = x ^ y;
    int cnt = 0;
    while(res>0){
        cnt += (res & 1);
        res >>= 1;
    }
    return cnt;
}