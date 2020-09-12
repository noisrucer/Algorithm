#include <iostream>
using namespace std;
long long dp[101][10];
long long MOD = 1000000000;



int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 101; i++) fill(dp[i], dp[i] + 10, 0);
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j >= 1) dp[i][j] += dp[i - 1][j - 1]%MOD;
            if (j <= 8)dp[i][j] += dp[i - 1][j + 1]%MOD;
            dp[i][j] %= MOD;
        }
    }
    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += dp[n][i];
        sum %= MOD;
    }
    cout << sum % MOD;
}