#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>P;
vector<int>dp;

int card(int N) {
	if (N == 0) return 0;
	if (dp[N]) return dp[N];
	for (int i = 1; i <= N; i++) {
		dp[N] = max(dp[N],P[i] + card(N - i));
	}
	return dp[N];
}
int main()
{
	int N;
	cin >> N;
	P = vector<int>(N+1);
	dp = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	cout << card(N);


}
