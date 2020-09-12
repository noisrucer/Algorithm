#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>P;

vector<int>dp;
int minVal = INT_MAX;

int func(int n) {
	if (n == 0) return 0;
	if (dp[n]!=1000*10000) return dp[n];
	for (int i = 1; i <= n; i++) {
		dp[n] = min(dp[n], P[i] + func(n - i));
		
	}
	
	return dp[n];
	
	
}
int main()
{
	int n;
	cin >> n;
	P = vector<int>(n + 1);
	dp = vector<int>(n + 1,1000*10000);
	for (int i = 1; i <= n; i++)
		cin >> P[i];
	cout << func(n);
	

}
