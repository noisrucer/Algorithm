int solve(int n, int a, int b) {
    if(a+b>=n) return n-a;
    else return b+1;
}