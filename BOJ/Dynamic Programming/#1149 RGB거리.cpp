
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[1002][4];
int cost[1002][4];
int topdown(int n, int i) {
	if (n == 1) {
		if (i == 1) return cost[1][1];
		if (i == 2) return cost[1][2];
		if (i == 3) return cost[1][3];
	}
	if (dp[n][i]) return dp[n][i];
	if (i == 1)
		dp[n][i] = cost[n][1]+min(topdown(n - 1, 2), topdown(n - 1, 3));
	if (i == 2)
		dp[n][i] = cost[n][2]+min(topdown(n - 1, 1), topdown(n - 1, 3));
	if (i == 3)
		dp[n][i] = cost[n][3]+min(topdown(n - 1, 1), topdown(n - 1, 2));

	return dp[n][i];
}

int main()
{
	int n;
	cin >> n;
	
		int min_cost = INT_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin>>cost[i][j];
			}
		}
		for (int i = 1; i <= 3; i++) {
			min_cost = min(min_cost, topdown(n, i));
		}
		cout << min_cost << endl;
	
}