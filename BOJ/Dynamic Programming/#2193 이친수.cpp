#include <iostream>
using namespace std;
long long dp[91][2];
long long MOD = 1000000000;

long long func(int n, int i) {
	if (n == 1) {
		if (i == 0) return 0;
		if (i == 1) return 1;
	}
	if (dp[n][i]) return dp[n][i];
	if (i == 0) dp[n][0] = func(n - 1, 0) + func(n - 1, 1);
	if (i == 1) dp[n][1] = func(n - 1, 0);
	return dp[n][i];

}

int main() {
	for (int i = 0; i < 91; i++) fill(dp[i], dp[i], 0);
	int n;
	cin >> n;
	cout << func(n,0)+func(n,1);
}