
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long
#define mod 1000000009LL
ll dp[1000001];
ll bottomup(ll n) {
	if (n <= 0) return 0;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (ll i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%mod;
	}
	return dp[n];
}
/*
ll topdown(ll n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (dp[n]) return dp[n];
	dp[n] = ((topdown(n - 1) % mod + topdown(n - 2) % mod) % mod + topdown(n - 3) % mod) % mod;
	return dp[n];
}
*/
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << bottomup(n)<<"\n";
	}
}