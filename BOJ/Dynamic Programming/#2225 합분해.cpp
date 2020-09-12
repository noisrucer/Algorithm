
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int>vec;
#define ll long long
#define mod 1000000000LL
ll dp[201][201];
ll topdown(ll n, ll k) {
	if (k == 0) return 0;
	if (k == 1) return 1;
	if (dp[n][k]) return dp[n][k];
	for (int i = 0; i <= n; i++) {
		dp[n][k] += (topdown(n - i, k - 1))%mod;
		dp[n][k] %= mod;
	}
	return dp[n][k];
}
int main()
{
	int n,k;
	cin >> n>>k;
	cout << topdown(n,k);


}
