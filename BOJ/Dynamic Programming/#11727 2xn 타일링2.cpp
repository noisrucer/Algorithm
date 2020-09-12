
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
	if (n == 2) return 3;
	if (dp[n] != 0) return dp[n];
	dp[n] = (tile(n - 1)%10007 + 2*tile(n - 2)%10007)%10007;
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	dp = vector<int>(n+1,0);
	cout << tile(n);
}