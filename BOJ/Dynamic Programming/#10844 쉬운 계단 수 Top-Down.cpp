#include <iostream>
using namespace std;
long long dp[101][10];
long long MOD = 1000000000;
long long func(int n, int l) {
    if (l < 0 || l>9) return 0;
    if (n == 1) {
        if (l == 0) return 0;
        return 1;
    }
    if (dp[n][l]) return dp[n][l];
    dp[n][l] = (func(n - 1, l - 1)%MOD + func(n - 1, l + 1) % MOD)%MOD;
    return dp[n][l];
   
}

int main() {
    int n;
    cin >> n;
    long long sum=0;
    for (int i = 0; i <= 9; i++) {
        sum += func(n, i);
        sum%=MOD;
    }
    cout << sum;
}