
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;
using ll = long long;
vector<int>dp;
int tile(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (dp[n] != 0) return dp[n];
	dp[n] = tile(n - 1) + tile(n - 2);
	return dp[n] % 10007;
}
int main() {
	int n;
	cin >> n;
	dp = vector<int>(n+1,0);
	cout << tile(n);
}