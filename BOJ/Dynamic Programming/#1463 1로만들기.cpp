
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int makeOne(int n) {
	if (n == 1) return 0;
	if (dp[n] != 0) return dp[n];
	dp[n] = makeOne(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = makeOne(n / 2) + 1;
		dp[n] = min(dp[n], temp);
	}
	if (n % 3 == 0) {
		int temp = makeOne(n / 3) + 1;
		dp[n] = min(dp[n], temp);
	}
	return dp[n];
}
int main()
{
	int n;
	cin >> n;
	cout<<makeOne(n);
	return 0;

}