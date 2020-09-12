#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;
int dp[11]{};
int sum(int n) {
	if (n == 1) return 1;
	if (n == 2)return 2;
	if (n == 3) return 4;
	if (dp[n]) return dp[n];
	dp[n] = sum(n - 1) + sum(n - 2) + sum(n - 3);
	return dp[n];
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << sum(n) << "\n";
	}

}