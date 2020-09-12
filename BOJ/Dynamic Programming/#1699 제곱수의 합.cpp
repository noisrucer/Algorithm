
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int>vec;
int dp[100001]{};
int topdown(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (dp[n]) return dp[n];
	int i = 1;
	int minVal = INT_MAX;
	while (i * i <= n) {
		dp[n] = 1 + topdown(n - i * i);
		minVal = min(minVal, dp[n]);
		i++;
	}
	dp[n] = minVal;
	return dp[n];
}
int main()
{
	int n;
	cin >> n;
	cout << topdown(n);


}
