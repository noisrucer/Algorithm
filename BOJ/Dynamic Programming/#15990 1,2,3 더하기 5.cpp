#include <stdio.h>
long long dp[1000001][4];
const long long MOD = 1000000009LL;
const int limit = 100000;

int main() {
	for (int i = 1; i <= limit; i++) {
		if (i - 1 >= 0) {
			dp[i][1] = dp[i - 1][2] + dp[i - 1][3];
			if (i == 1) dp[i][1] = 1;
		}
		if (i - 2 >= 0) {
			dp[i][2] = dp[i - 2][1] + dp[i - 2][3];
			if (i == 2) dp[i][2] = 1;
		}
		if (i - 3 >= 0) {
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2];
			if (i == 3) dp[i][3] = 1;
		}
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
		dp[i][3] %= MOD;
   }
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d",&n);
		printf("%lld\n",(dp[n][1] + dp[n][2] + dp[n][3]) % MOD);
	}
}