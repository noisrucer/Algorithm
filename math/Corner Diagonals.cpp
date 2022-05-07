int solve(int n) {
    return n*n - (n & 1 ? 2*n-1 : 2*n);
}