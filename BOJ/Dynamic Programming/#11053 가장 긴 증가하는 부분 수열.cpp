
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> A(n+1);
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	
	vector<int>dp(n+1);
	for (int i = 1; i <=n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && dp[j] + 1>dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());
	
}
