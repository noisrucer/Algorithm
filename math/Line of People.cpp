int solve(int n, int a, int b) {
    if(a+b>=n) return n-a;
    else return b+1;
}int solve(int n, int a, int b) {
    return a+b >= n ? n-a : b+1;
}